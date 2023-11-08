#include <iostream>
#include <stdexcept>
#include <cmath>

using namespace std;

class CashSuper
{
public:
    // 当标价转换成实收价格
    virtual double acceptCash(double money)
    {
        return 0.0;
    }
};

class CashNormal : public CashSuper
{
public:
    double acceptCash(double money) override
    {
        return money;
    }
};

class CashRebate : public CashSuper
{
private:
    double moneyRebate;
public:
    //rebate表示打几折，比如打8折，则rebate = 0.8
    CashRebate(double rebate)
    {
        moneyRebate = rebate;
    }

    double acceptCash(double money) override
    {
        return money * moneyRebate;
    }
};

class CashReturn : public CashSuper
{
private:
    double moneyCondition;
    double moneyReturn;
public:
    //返利模式，比如满300返100，此时condition=300,ret=100
    CashReturn(double condition, double ret)
    {
        moneyCondition = condition;
        moneyReturn = ret;
    }

    double acceptCash(double money) override
    {
        double result = money;
        if (money >= moneyCondition)
        {
            result = money - floor(money / moneyCondition) * moneyReturn;
        }
        return result;
    }
};

class CashContext
{
private:
    CashSuper *cs = nullptr;
public:
    CashContext(string type)
    {
        if ("正常收费" == type)
        {
            cs = new CashNormal();
        }
        else if ("满300返100" == type)
        {
            cs = new CashReturn(300, 100);
        }
        else if ("打8折" == type)
        {
            cs = new CashRebate(0.8);
        }
    }
    double getResult(double money)
    {
        return cs->acceptCash(money);
    }
};

int main()
{
    double total = 0.0;
    string type = "满300返100";
    CashContext* csuper = new CashContext(type);
    double price = 50;
    double number = 7;
    double totalPrices = csuper->getResult(price * number);
    total += totalPrices;

    cout << "单价：" << price <<  " 数量：" << number << " 收费模式：" << type << " 合计： " << totalPrices << endl;

    return 0;
}