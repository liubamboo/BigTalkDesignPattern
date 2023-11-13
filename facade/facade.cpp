#include <iostream>
#include <string>

using namespace std;

class SubSystemOne
{
public:
    void MethodOne()
    {
        cout << "子系统方法一" << endl;
    }
};

class SubSystemTwo
{
public:
    void MethodTwo()
    {
        cout << "子系统方法二" << endl;
    }
};

class SubSystemThree
{
public:
    void MethodThree()
    {
        cout << "子系统方法三" << endl;
    }
};

class SubSystemFour
{
public:
    void MethodFour()
    {
        cout << "子系统方法四" << endl;
    }
};

class Facade
{
private:
    SubSystemOne     *pOne;
    SubSystemTwo     *pTwo;
    SubSystemThree   *pThree;
    SubSystemFour    *pFour;

public:
    Facade()
    {
        pOne   = new SubSystemOne();
        pTwo   = new SubSystemTwo();
        pThree = new SubSystemThree();
        pFour  = new SubSystemFour();
    }

    void MethodA()
    {
        cout << endl << "方法组A() ---- " << endl;
        pOne->MethodOne();
        pTwo->MethodTwo();
        pFour->MethodFour();
    }

    void MethodB()
    {
        cout << endl << "方法组B() ---- " << endl;
        pTwo->MethodTwo();
        pThree->MethodThree();
    }
};

int main()
{
    Facade *pFacade = new Facade();

    pFacade->MethodA();
    pFacade->MethodB();
    return 0;
}