#include <iostream>
#include <typeinfo>
#include <vector>

using namespace std;

class Handler
{
protected:
    Handler *successor;
public:
    Handler(Handler* p = nullptr) : successor(p) {}
    void SetSuccessor(Handler *successor)
    {
        this->successor = successor;
    }

    virtual void HandleRequest(int request) = 0;
    virtual ~Handler() {}
};

class ConcreteHandler1 : public Handler
{
public:
    void HandleRequest(int request) override
    {
        if (request >= 0 && request < 10)
        {
            cout << typeid(*this).name() << " handle request " << request << endl;
        }
        else if (successor != nullptr)
        {
            successor->HandleRequest(request);
        }
    }
};

class ConcreteHandler2 : public Handler
{
public:
    void HandleRequest(int request) override
    {
        if (request >= 10 && request < 20)
        {
            cout << typeid(*this).name() << " handle request " << request << endl;
        }
        else if (successor != nullptr)
        {
            successor->HandleRequest(request);
        }
    }
};

class ConcreteHandler3 : public Handler
{
public:
    void HandleRequest(int request) override
    {
        if (request >= 20 && request < 30)
        {
            cout << typeid(*this).name() << " handle request " << request << endl;
        }
        else if (successor != nullptr)
        {
            successor->HandleRequest(request);
        }
    }
};

int main()
{
    Handler *pH1 = new ConcreteHandler1();
    Handler *pH2 = new ConcreteHandler2();
    Handler *pH3 = new ConcreteHandler3();
    pH1->SetSuccessor(pH2);
    pH2->SetSuccessor(pH3);

    vector<int> requests{2, 5, 14, 22, 18, 3, 27, 20};
    for (auto m : requests)
    {
        pH1->HandleRequest(m);
    }

    delete pH3;
    pH3 = nullptr;
    delete pH2;
    pH2 = nullptr;
    delete pH1;
    pH1 = nullptr;

    return 0;
}