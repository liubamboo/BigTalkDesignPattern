#include <iostream>
#include <string>
#include <list>

using namespace std;

class Product
{
private:
    list<string> parts;
public:
    void Add(string part)
    {
        parts.push_back(part);
    }

    void Show()
    {
        cout << endl << "产品 创建 ----" << endl;
        for(auto it = parts.begin(); it != parts.end(); ++it)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
};

class Builder
{
public:
    virtual void BuildPartA() = 0;
    virtual void BuildPartB() = 0;
    virtual Product* GetResult() = 0;
};

class ConcreteBuilder1 : public Builder
{
private:
    Product *pProduct;
public:
    ConcreteBuilder1()
    {
        pProduct = new Product();
    }

    void BuildPartA() override
    {
        pProduct->Add("部件A");
    }

    void BuildPartB() override
    {
        pProduct->Add("部件B");
    }

    Product* GetResult() override
    {
        return pProduct;
    }
};

class ConcreteBuilder2 : public Builder
{
private:
    Product *pProduct;
public:
    ConcreteBuilder2()
    {
        pProduct = new Product();
    }
    
    void BuildPartA() override
    {
        pProduct->Add("部件X");
    }

    void BuildPartB() override
    {
        pProduct->Add("部件Y");
    }

    Product* GetResult() override
    {
        return pProduct;
    }
};

class Director
{
public:
    void Construct(Builder *pBuilder)
    {
        pBuilder->BuildPartA();
        pBuilder->BuildPartB();
    }
};

int main()
{
    Director *pDirector = new Director();
    Builder *pb1 = new ConcreteBuilder1();
    Builder *pb2 = new ConcreteBuilder2();

    pDirector->Construct(pb1);
    Product *pp1 = pb1->GetResult();
    pp1->Show();

    pDirector->Construct(pb2);
    Product *pp2 = pb2->GetResult();
    pp2->Show();

    return 0;
}