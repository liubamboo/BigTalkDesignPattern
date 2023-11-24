#include <iostream>
#include <list>
#include <string>

using namespace std;

class Company
{
protected:
    string name;
public:
    Company(string name) : name(name) {}

    virtual void Add(Company *pc) = 0;
    virtual void Remove(Company *pc) = 0;
    virtual void Display(int depth) = 0;
    virtual void LineOfDuty() = 0;
};

class ConcreteCompany : public Company
{
private:
    list<Company*> children;
public:
    ConcreteCompany(string name) : Company(name) {}

    void Add(Company* pc) override
    {
        children.push_front(pc);
    }

    void Remove(Company* pc) override
    {
        children.remove(pc);
    }

    void Display(int depth) override
    {
        cout << string(depth, '-') << Company::name << endl;
        for (auto m : children)
        {
            m->Display(depth + 2);
        }
    }

    void LineOfDuty() override
    {
        for (auto m : children)
        {
            m->LineOfDuty();
        }
    }
};

class HRDepartment : public Company
{
public:
    HRDepartment(string name) : Company(name) {}

    void Add(Company* pc) override
    {

    }

    void Remove(Company* pc) override
    {

    }

    void Display(int depth) override
    {
        cout << string(depth, '-') << name << endl;
    }

    void LineOfDuty() override
    {
        cout << name << " 员工招聘培训管理" << endl;
    }
};

class FinanceDepartment : public Company
{
public:
    FinanceDepartment(string name) : Company(name) {}

    void Add(Company *pc) override
    {

    }

    void Remove(Company *pc) override
    {

    }

    void Display(int depth) override
    {
        cout << string(depth, '-') << name << endl;
    }

    void LineOfDuty() override
    {
        cout << name << " 公司财务收支管理" << endl;
    }
};

int main()
{
    ConcreteCompany *root = new ConcreteCompany("北京总公司");
    root->Add(new HRDepartment("总公司人力资源部"));
    root->Add(new FinanceDepartment("总公司财务部"));

    ConcreteCompany *comp = new ConcreteCompany("上海华东分公司");
    comp->Add(new HRDepartment("华东分公司人力资源部"));
    comp->Add(new FinanceDepartment("华东分公司财务部"));
    root->Add(comp);

    ConcreteCompany *comp1 = new ConcreteCompany("南京办事处");
    comp1->Add(new HRDepartment("南京办事处人力资源部"));
    comp1->Add(new FinanceDepartment("南京办事处财务部"));
    comp->Add(comp1);

    ConcreteCompany *comp2 = new ConcreteCompany("杭州办事处");
    comp2->Add(new HRDepartment("杭州办事处人力资源处"));
    comp2->Add(new FinanceDepartment("杭州办事处财务部"));
    comp->Add(comp2);

    cout << "组织结构图：" << endl;
    root->Display(1);

    cout << "职责:" << endl;
    root->LineOfDuty();

    return 0;
}