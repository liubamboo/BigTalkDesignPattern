#include <iostream>
#include <string>
#include <list>

using namespace std;

/*
 * 非委托模式实现观测者模式
 */

class Subject;

// 抽象观察者
class Observer
{
protected:
    string name;
    Subject *pSub;
public:
    Observer(string name, Subject *pSub) : name(name), pSub(pSub) {}
    virtual void Update() = 0;
};

// 通知者接口
class Subject
{
public:
    virtual void Attach(Observer* pObserver) = 0;
    virtual void Detach(Observer* pObserver) = 0;
    virtual void Notify() = 0;
    virtual string GetState() const = 0;
    virtual void SetState(string action) = 0;
};

// 看股票的同事
class StockObserver : public Observer
{
public:
    StockObserver(string name, Subject *pSub) : Observer(name, pSub) {}
    void Update() override
    {
        cout << pSub->GetState() << "," << name << "关闭股票行情,继续工作!" << endl;
    }
};

// 看NBA的同事
class NBAObserver : public Observer
{
public:
    NBAObserver(string name, Subject *pSub) : Observer(name, pSub) {}
    void Update() override
    {
        cout << pSub->GetState() << "," << name << "关闭NBA直播,继续工作!" << endl;
    }
 };

class Boss : public Subject
{
private:
    list<Observer*> pObservers;
    string action;
public:
    void Attach(Observer *pObserver) override
    {
        pObservers.push_back(pObserver);
    }

    void Detach(Observer *pObserver) override
    {
        pObservers.remove(pObserver);
    }

    void Notify() override
    {
        for (auto it = pObservers.begin(); it != pObservers.end(); ++it)
        {
            (*it)->Update();
        }
    }

    string GetState() const override
    {
        return action;
    }

    void SetState(string action) override
    {
        this->action = action;
    }
};

int main()
{
    Boss *pHuhansan = new Boss();

    StockObserver *pTongshi1 = new StockObserver("魏关宅", pHuhansan);
    NBAObserver   *pTongshi2 = new NBAObserver("易管查", pHuhansan);

    pHuhansan->Attach(pTongshi1);
    pHuhansan->Attach(pTongshi2);

    // 魏关宅其实没有被老板通知到，所以减去
    pHuhansan->Detach(pTongshi1);

    pHuhansan->SetState("我胡汉三回来了");
    pHuhansan->Notify();

    return 0;
}