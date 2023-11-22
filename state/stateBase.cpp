#include <iostream>
#include <typeinfo>

using namespace std;

class Context;

class State
{
public:
    virtual void Handle(Context *pContext) = 0;
    virtual ~State() {} //父类析构函数需要设置成虚函数，并且需要实现
};

class Context
{
private:
    State *pState;
public:
    Context(State *pState)
    {
        this->pState = pState;
    }
    State* GetState()
    {
        return pState;
    }
    void SetState(State* pVal)
    {
        pState = pVal;
        cout << "当前状态：" << typeid(*pState).name() << endl;
    }
    void Request()
    {
        pState->Handle(this);
    }
    ~Context()
    {
        delete pState;
    }
};

class ConcreteStateA : public State
{
public:
    void Handle(Context *pContext) override;
};

class ConcreteStateB : public State
{
public:
    void Handle(Context *pContext) override
    {
        pContext->SetState(new ConcreteStateA);
    }
};

void ConcreteStateA::Handle(Context *pContext)
{
    pContext->SetState(new ConcreteStateB);
}

int main()
{
    Context *pC = new Context(new ConcreteStateA);

    pC->Request();
    pC->Request();
    pC->Request();
    pC->Request();

    delete pC;

    return 0;
}