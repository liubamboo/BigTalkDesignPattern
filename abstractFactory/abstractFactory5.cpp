#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

/*
 * 抽象工厂模式基本代码
 */

class AbstractProductA
{
public:
    virtual string GetName()
    {
        return typeid(*this).name();
    }
};

class AbstractProductB
{
public:
    virtual void Interact(AbstractProductA* pa) = 0;
};

class ProductA1 : public AbstractProductA
{

};

class ProductB1 : public AbstractProductB
{
public:
    void Interact(AbstractProductA* pa) override
    {
        // typeid(a)用于获取std::info对象，它的name方法对应a的类名
        cout << typeid(*this).name() << " interacts with " << pa->GetName() << endl;
    }
};

class ProductA2 : public AbstractProductA
{

};

class ProductB2 : public AbstractProductB
{
public:
    void Interact(AbstractProductA* pa) override
    {
        cout << typeid(*this).name() << " interacts with " << pa->GetName() << endl;
    }
};

class AbstractFactory
{
public:
    virtual AbstractProductA* CreateProductA() = 0;
    virtual AbstractProductB* CreateProductB() = 0;
};

class ConcreteFactory1 : public AbstractFactory
{
public:
    AbstractProductA* CreateProductA() override
    {
        return new ProductA1();
    }

    AbstractProductB* CreateProductB() override
    {
        return new ProductB1();
    }
};

class ConcreteFactory2 : public AbstractFactory
{
public:
    AbstractProductA* CreateProductA() override
    {
        return new ProductA2();
    }

    AbstractProductB* CreateProductB() override
    {
        return new ProductB2();
    }
};

class Client
{
public:
    Client(AbstractFactory* pFactory)
    {
        pAbsPrtA = pFactory->CreateProductA();
        pAbsPrtB = pFactory->CreateProductB();
    }

    void Run()
    {
        pAbsPrtB->Interact(pAbsPrtA);
    }
private:
    AbstractProductA *pAbsPrtA;
    AbstractProductB *pAbsPrtB;
};

int main()
{
    AbstractFactory *pFactory1 = new ConcreteFactory1();
    Client *pc1 = new Client(pFactory1);
    pc1->Run();

    AbstractFactory *pFactory2 = new ConcreteFactory2();
    Client *pc2 = new Client(pFactory2);
    pc2->Run();

    return 0;
}