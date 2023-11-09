#include <iostream>

using namespace std;

class LeiFeng
{
public:
    void Sweep()
    {
        cout << "扫地" << endl;
    }

    void Wash()
    {
        cout << "洗衣" << endl;
    }

    void BuyRice()
    {
        cout << "买米" << endl;
    }
};

class Undergraduate : public LeiFeng
{

};

class Volunteer : public LeiFeng
{

};


class IFactory
{
public:
    virtual LeiFeng* CreateLeiFeng()
    {
        return new LeiFeng();
    }
};

class VolunteerFactory : public IFactory
{
public:
    LeiFeng* CreateLeiFeng() override
    {
        return new Volunteer();
    }
};

class UndergraduateFactory : public IFactory
{
public:
    LeiFeng* CreateLeiFeng() override
    {
        return new Undergraduate();
    }
};

int main()
{
    IFactory *pFactory = new UndergraduateFactory();
    LeiFeng *pStudent = pFactory->CreateLeiFeng();

    pStudent->BuyRice();
    pStudent->Sweep();
    pStudent->Wash();


    return 0;
}