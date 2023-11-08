#include <iostream>
#include <stdexcept>


using namespace std;

class Number
{
private:
    double _number;
public:
    double Get() 
    {
        return _number;
    }
    void Set(double value)
    {
        _number = value;
    }
};

class Operation
{
public:
    Number numberA;
    Number numberB;

    virtual double getResult()
    {
        double result = 0;
        return result;
    }

};

class OperationAdd : public Operation
{
public: 
    double getResult () override
    {
        double result = 0;
        result = numberA.Get() + numberB.Get();
        return result;
    }
};

class OperationSub : public Operation
{
public:
    double getResult () override
    {
        double result = 0;
        result = numberA.Get() - numberB.Get();
        return result;
    }
};

class OperationMul : public Operation
{
public:
    double getResult () override
    {
        double result = 0;
        result = numberA.Get() * numberB.Get();
        return result;
    }
};

class OperationDiv : public Operation
{
public: 
    double getResult () override
    {
        double result = 0;
        if (numberB.Get() == 0)
        {
            throw runtime_error("Division by zero is not allowed");
        }
        result = numberA.Get() / numberB.Get();
        return result;
    }
};


class OperationFactory
{
public:
    static Operation* createOperation(string operate)
    {
        Operation* operPtr = nullptr;
        if ("+" == operate)
        {
            operPtr = new OperationAdd();
        }
        else if ("-" == operate)
        {
            operPtr = new OperationDiv();
        }
        else if ("*" == operate)
        {
            operPtr = new OperationMul();
        }
        else if ("/" == operate)
        {
            operPtr = new OperationDiv();
        }

        return operPtr;
    }
};

int main()
{
    Operation* operPtr = OperationFactory::createOperation ("+");
    operPtr->numberA.Set(1);
    operPtr->numberB.Set(2);
    double result = operPtr->getResult();
    cout << "The result is " << result << endl;
    return 0;
}