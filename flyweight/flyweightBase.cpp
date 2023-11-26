#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Flyweight
{
public:
    virtual void Operation(int extrinsicstate) = 0;
    virtual ~Flyweight() {}
};

class ConcreteFlyweight : public Flyweight
{
public:
    void Operation(int extrinsicstate) override
    {
        cout << "具体Flyweight:" << extrinsicstate << endl;
    }
};

class UnsharedConcreteFlyweight : public Flyweight
{
public:
    void Operation(int extrinsicstate) override
    {
        cout << "不共享的具体Flyweight:" << extrinsicstate << endl;
    }
};

class FlyweightFactory
{
private:
    unordered_map<string, ConcreteFlyweight*> flyweights;
public:
    FlyweightFactory()
    {
        flyweights["X"] = new ConcreteFlyweight();
        flyweights["Y"] = new ConcreteFlyweight();
        flyweights["Z"] = new ConcreteFlyweight();
    }

    Flyweight* GetFlyweight(string key)
    {
        return flyweights[key];
    }
};

int main()
{
    int extrinsicstate = 22; // 外部状态

    FlyweightFactory *pf = new FlyweightFactory();

    Flyweight *pfx = pf->GetFlyweight("X");
    pfx->Operation(--extrinsicstate);

    Flyweight *pfy = pf->GetFlyweight("Y");
    pfy->Operation(--extrinsicstate);

    Flyweight *pfz = pf->GetFlyweight("Z");
    pfz->Operation(--extrinsicstate);

    UnsharedConcreteFlyweight *puf = new UnsharedConcreteFlyweight();
    puf->Operation(--extrinsicstate);
    return 0;
}