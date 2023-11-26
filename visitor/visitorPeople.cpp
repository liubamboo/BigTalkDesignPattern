#include <iostream>
#include <typeinfo>
#include <list>

using namespace std;

class Person;

class Action
{
public:
    virtual void GetManConclusion(Person *elementA) = 0;
    virtual void GetWomanConclusion(Person *elementB) = 0;
    virtual ~Action()
    {

    }
};

class Person
{
public:
    virtual void Accept(Action *visitor) = 0;
    ~Person()
    {

    }
};

class Success : public Action
{
public:
    void GetManConclusion(Person *elementA) override
    {
        cout << typeid(*elementA).name() << typeid(*this).name() << "时，背后多半有个伟大的女人" << endl;
    }

    void GetWomanConclusion(Person *elementB) override
    {
        cout << typeid(*elementB).name() << typeid(*this).name() << "时，背后大多有一个不成功的男人" << endl;
    }
};

class Failing : public Action
{
public:
    void GetManConclusion(Person *elementA) override
    {
        cout << typeid(*elementA).name() << typeid(*this).name() << "时，闷头喝酒，谁也不用劝" << endl;
    }
    void GetWomanConclusion(Person *elementB) override
    {
        cout << typeid(*elementB).name() << typeid(*this).name() << "时，眼泪汪汪，谁也劝不了" << endl;
    }
};

class Amativeness : public Action
{
public:
    void GetManConclusion(Person *elementA) override
    {
        cout << typeid(*elementA).name() << typeid(*this).name() << "时，凡事不懂也要装懂" << endl;
    }
    void GetWomanConclusion(Person *elementB) override
    {
        cout << typeid(*elementB).name() << typeid(*this).name() << "时，遇事懂也装不懂" << endl;
    }
};

class Marriage : public Action
{
public:
    void GetManConclusion(Person *elementA) override
    {
        cout << typeid(*elementA).name() << typeid(*this).name() << "时，有妻徒刑遥无期" << endl;
    }
    void GetWomanConclusion(Person *elementB) override
    {
        cout << typeid(*elementB).name() << typeid(*this).name() << "时，婚姻保险保平安" << endl;
    }
};

class Man : public Person
{
public:
    void Accept(Action *visitor)
    {
        visitor->GetManConclusion(this);
    }
};

class Woman : public Person
{
public:
    void Accept(Action *visitor)
    {
        visitor->GetWomanConclusion(this);
    }
};

class ObjectStructure
{
private:
    list<Person*> people;
public:
    void Attach(Person *p)
    {
        people.push_front(p);
    }

    void Detach(Person *p)
    {
        people.remove(p);
    }

    void Display(Action *pv)
    {
        for (auto l : people)
        {
            l->Accept(pv);
        }
    }
};

int main()
{
    ObjectStructure *po = new ObjectStructure();
    po->Attach(new Man());
    po->Attach(new Woman());

    Success *pv1 = new Success();
    po->Display(pv1);

    Failing *pv2 = new Failing();
    po->Display(pv2);

    Amativeness *pv3 = new Amativeness();
    po->Display(pv3);

    Marriage *pv4 = new Marriage();
    po->Display(pv4);

    return 0;
}