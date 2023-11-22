#include <iostream>
#include <typeinfo>

using namespace std;

class Context;

class State
{
protected:
    Context *pContext;
public:
    virtual ~State() {}
    void SetContext(Context *pContext)
    {
        this->pContext = pContext;
    }

    virtual void Handle1() = 0;
    virtual void Handle2() = 0;
};

class Context
{
private:
    State *pState;
public:
    Context(State *pState) : pState(nullptr)
    {
        this->TransitionTo(pState);
    }

    ~Context()
    {
        delete pState;
    }

    void TransitionTo(State* pState)
    {
        cout << "Context: Transition to " << typeid(*pState).name() << endl;
        if (this->pState != nullptr) delete this->pState;
        this->pState = pState;
        this->pState->SetContext(this);
    }

    void Request1()
    {
        this->pState->Handle1();
    }

    void Request2()
    {
        this->pState->Handle2();
    }
};

class ConcreteStateA : public State
{
public:
    void Handle1() override;

    void Handle2() override
    {
        cout << "ConcreteStateA handles request2" << endl;
    }
};

class ConcreteStateB : public State
{
public:
    void Handle1() override
    {
        cout << "ConcreteStateB handle request1" << endl;
    }

    void Handle2() override
    {
        cout << "ConcreteStateB handle request2" << endl;
        cout << "ConcreteStateB wants to change to the state of the context" << endl;
        this->pContext->TransitionTo(new ConcreteStateA);
    }
};

void ConcreteStateA::Handle1()
{
    cout << "ConcreteStateA handles request1" << endl;
    cout << "ConcreteStateA want to change to the state of the context" << endl;
    this->pContext->TransitionTo(new ConcreteStateB);
}

void ClientCode()
{
    Context *pContext = new Context(new ConcreteStateA);
    pContext->Request1();
    pContext->Request2();
    delete pContext;
}

int main()
{
    ClientCode();
    return 0;
}