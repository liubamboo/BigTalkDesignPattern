#include <iostream>
#include <string>

using namespace std;

class SchoolGirl
{
private:
    string _name;
public:
    SchoolGirl(string name)
    {
        _name = name;
    }
    string& Get()
    {
        return _name;
    }
};

//接口
class GiveGift
{
public:
    virtual void GiveDolls(){}
    virtual void GiveFlowers(){}
    virtual void GiveChocolate(){}
};

class Pursuit : public GiveGift
{
private:
    SchoolGirl *_pMm;
public:
    Pursuit(SchoolGirl *pMm)
    {
        _pMm = pMm;
    }
    void GiveDolls() override
    {
        cout << _pMm->Get() << "送你洋娃娃" << endl;
    }
    void GiveFlowers() override
    {
        cout << _pMm->Get() << "送你鲜花" << endl;
    }
    void GiveChocolate() override
    {
        cout << _pMm->Get() << "送你巧克力" << endl;
    }
};

class Proxy : public GiveGift
{
private:
    Pursuit *pGg;
public:
    Proxy(SchoolGirl *pMm)
    {
        pGg = new Pursuit(pMm);
    }
    void GiveDolls() override
    {
        pGg->GiveDolls();
    }
    void GiveFlowers() override
    {
        pGg->GiveFlowers();
    }
    void GiveChocolate() override
    {
        pGg->GiveChocolate();
    }
};


int main()
{
    SchoolGirl *pJiaojiao = new SchoolGirl("李娇娇");

    Proxy *pDaili = new Proxy(pJiaojiao);

    pDaili->GiveDolls();
    pDaili->GiveFlowers();
    pDaili->GiveChocolate();

    return 0;
}