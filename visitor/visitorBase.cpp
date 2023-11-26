#include <iostream>
#include <typeinfo>
#include <list>

using namespace std;

class Visitor;

class Element
{
public:
    virtual void Accept(Visitor *visitor) = 0;
    ~Element()
    {

    }
};

class Visitor
{
public:
    virtual void VisitConcreteElementA(Element *ElementA) = 0;
    virtual void VisitConcreteElementB(Element *ElementB) = 0;
    virtual ~Visitor()
    {

    }
};

class ConcreteElementA : public Element
{
public:
    void Accept(Visitor *visitor) override
    {
        visitor->VisitConcreteElementA(this);
    }

    void OperationA()
    {

    }
};

class ConcreteElementB : public Element
{
public:
    void Accept(Visitor *visitor) override
    {
        visitor->VisitConcreteElementB(this);
    }

    void OperationB()
    {

    }
};

class ConcreteVisitor1 : public Visitor
{
public:
    void VisitConcreteElementA(Element *pa) override
    {
        cout << typeid(*pa).name() << "被" << typeid(*this).name() << "访问" << endl;
    }

    void VisitConcreteElementB(Element *pb) override
    {
        cout << typeid(*pb).name() << "被" << typeid(*this).name() << "访问" << endl;
    }
};

class ConcreteVisitor2 : public Visitor
{
public:
    void VisitConcreteElementA(Element *pa) override
    {
        cout << typeid(*pa).name() << "被" << typeid(*this).name() << "访问" << endl;
    }

    void VisitConcreteElementB(Element *pb) override
    {
        cout << typeid(*pb).name() << "被" << typeid(*this).name() << "访问" << endl;
    }
};

class ObjectStructure
{
private:
    list<Element*> elements;
public:
    void Attach(Element *pe)
    {
        elements.push_front(pe);
    }

    void Detach(Element *pe)
    {
        elements.remove(pe);
    }

    void Accept(Visitor *pv)
    {
        for (auto l : elements)
        {
            l->Accept(pv);
        }
    }
};

int main()
{
    ObjectStructure *po = new ObjectStructure();
    po->Attach(new ConcreteElementA());
    po->Attach(new ConcreteElementB());

    ConcreteVisitor1 *pv1 = new ConcreteVisitor1();
    ConcreteVisitor2 *pv2 = new ConcreteVisitor2();

    po->Accept(pv1);
    po->Accept(pv2);

    return 0;
}