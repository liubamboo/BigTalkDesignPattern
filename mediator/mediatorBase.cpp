#include <iostream>

using namespace std;

class Mediator;

class Colleague
{
protected:
    Mediator *pMediator;
public:
    Colleague(Mediator *pm) : pMediator(pm) {}
    virtual ~Colleague() {}
    virtual void Send(string message) = 0;
    virtual void Notify(string message) = 0;
};

class Mediator
{
public:
    virtual void Send(string message, Colleague *pc) = 0;
    virtual ~Mediator() {}
};

class ConcreteColleague1 : public Colleague
{
public:
    ConcreteColleague1(Mediator *pm) : Colleague(pm)
    {

    }

    void Send(string message) override
    {
        pMediator->Send(message, this);
    }

    void Notify(string message) override
    {
        cout << "同事1得到信息:" << message << endl;
    }
};

class ConcreteColleague2 : public Colleague
{
public:
    ConcreteColleague2(Mediator *pm) : Colleague(pm)
    {

    }

    void Send(string message) override
    {
        pMediator->Send(message, this);
    }

    void Notify(string message) override
    {
        cout << "同事2得到消息:" << message << endl;
    }
};


class ConcreteMediator : public Mediator
{
private:
    ConcreteColleague1 *pColleague1;
    ConcreteColleague2 *pColleague2;
public:
    void SetConcreteColleague1(ConcreteColleague1 *pc)
    {
        pColleague1 = pc;
    }

    void SetConcreteColleague2(ConcreteColleague2 *pc)
    {
        pColleague2 = pc;
    }

    void Send(string message, Colleague *pc)
    {
        if (pc == pColleague1)
        {
            pColleague2->Notify(message);
        }
        else
        {
            pColleague1->Notify(message);
        }
    }
};

int main()
{
    ConcreteMediator *pm = new ConcreteMediator();

    ConcreteColleague1 *pc1 = new ConcreteColleague1(pm);
    ConcreteColleague2 *pc2 = new ConcreteColleague2(pm);

    pm->SetConcreteColleague1(pc1);
    pm->SetConcreteColleague2(pc2);

    pc1->Send("吃过饭了吗？");
    pc2->Send("没有呢，你打算请客？");

    return 0;
}