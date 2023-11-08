#include <iostream>
#include <string>

using namespace std;

class Person
{
private:
    string _name;
public:
    Person() {}
    Person(string name)
    {
        _name = name;
    }
    virtual void Show()
    {
        cout << "装扮的" << _name << endl;
    }
};

class Finery : public Person
{
protected:
    Person *_pComponent;
public:
    void Decorate(Person *pComponent)
    {
        _pComponent = pComponent;
    }

    void Show() override
    {
        _pComponent->Show();
    }
};

class TShirts : public Finery
{
public:
    void Show() override
    {
        cout << "大T恤 ";
        Finery::Show();
    }
};

class BigTrouser : public Finery
{
public:
    void Show() override
    {
        cout << "跨裤 ";
        Finery::Show();
    }
};

class Sneakers : public Finery
{
public:
    void Show() override
    {
        cout << "破球鞋 ";
        Finery::Show();
    }
};

class Suit : public Finery
{
public:
    void Show() override
    {
        cout << "西装 " << endl;
        Finery::Show();
    }
};

class Tie : public Finery
{
public:
    void Show() override
    {
        cout << "领带 " ;
        Finery::Show();
    }
};

class LeatherShoes : public Finery
{
public:
    void Show() override
    {
        cout << "皮鞋 ";
        Finery::Show();
    }
};

int main()
{
    Person *pXiaocai = new Person("小菜");

    cout << "第一种装扮：" << endl;
    Sneakers    *pPqx  = new Sneakers();
    BigTrouser  *pKk   = new BigTrouser();
    TShirts     *pDtx  = new TShirts();

    pPqx->Decorate(pXiaocai);
    pKk->Decorate(pPqx);
    pDtx->Decorate(pKk);
    pDtx->Show();

    cout << "第二种装扮：" << endl;
    LeatherShoes    *pPx  = new LeatherShoes();
    Tie             *pLd  = new Tie();
    Suit            *pXz  = new Suit();

    pPx->Decorate(pXiaocai);
    pLd->Decorate(pPx);
    pXz->Decorate(pLd);
    pXz->Show();

    cout << "第三种装扮：" << endl;
    Sneakers     *pPqx2 = new Sneakers();
    LeatherShoes *pPx2  = new LeatherShoes();
    BigTrouser   *pKk2  = new BigTrouser();
    Tie          *pLd2  = new Tie();

    pPqx2->Decorate(pXiaocai);
    pPx2->Decorate(pPqx);
    pKk2->Decorate(pPx2);
    pLd2->Decorate(pKk2);
    pLd2->Show();

    return 0;
}