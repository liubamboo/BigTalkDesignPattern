#include <iostream>
#include <list>
#include <chrono>
#include <ctime>
#include <string>

using namespace std;

class Barbecuer
{
public:
    void BakeMutton()
    {
        cout << "烤羊肉串！" << endl;
    }

    void BakeChickenWing()
    {
        cout << "烤鸡翅！" << endl;
    }
};

class Command
{
protected:
    Barbecuer *pReceiver;
public:
    Command(Barbecuer *pReceiver) : pReceiver(pReceiver) {}
    virtual void ExecuteCommand() = 0;
    virtual string Name() = 0;
    ~Command() {}
};

class BakeMuttonCommand : public Command
{
public:
    BakeMuttonCommand(Barbecuer *pReceiver) : Command(pReceiver)
    {
    }

    void ExecuteCommand() override
    {
        pReceiver->BakeMutton();
    }

    string Name() override
    {
        return "BakeMuttonCommand";
    }
};

class BakeChickenWingCommand : public Command
{
public:
    BakeChickenWingCommand(Barbecuer *pReceiver) : Command(pReceiver) {}

    void ExecuteCommand() override
    {
        pReceiver->BakeChickenWing();
    }

    string Name() override
    {
        return "BakeChickenWingCommand";
    }
};

class Waiter
{
private:
    list<Command*> orders;
public:
    void SetOrder(Command *pCommand)
    {
        if (pCommand->Name() == "BakeChickenWingCommand")
        {
            cout << "服务员：鸡翅没有了，请点别的烧烤。" << endl;
        }
        else
        {
            orders.push_front(pCommand);
            auto currentTime = chrono::system_clock::now();
            time_t currentTimeT = chrono::system_clock::to_time_t(currentTime);
            cout << "增加订单：" << pCommand->Name() << " 时间：" << ctime(&currentTimeT) << endl;
        }
    }

    void CancelOrder(Command *pCommand)
    {
        orders.remove(pCommand);
        auto currentTime = chrono::system_clock::now();
        time_t currentTimeT = chrono::system_clock::to_time_t(currentTime);
        cout << "取消订单：" << pCommand->Name() << " 时间：" << ctime(&currentTimeT) << endl;
    }

    void Notify()
    {
        for (auto m : orders)
        {
            m->ExecuteCommand();
        }
    }
};


int main()
{
    // 开店前的准备
    Barbecuer *pBoy = new Barbecuer();
    Command *pBakeMuttonCommand1 = new BakeMuttonCommand(pBoy);
    Command *pBakeMuttonCommand2 = new BakeMuttonCommand(pBoy);
    Command *pBakeChickenWingCommand1 = new BakeChickenWingCommand(pBoy);
    Waiter *pGirl = new Waiter();

    // 开门营业，顾客点菜
    pGirl->SetOrder(pBakeMuttonCommand1);
    pGirl->SetOrder(pBakeMuttonCommand2);
    pGirl->SetOrder(pBakeChickenWingCommand1);

    // 点菜完毕，通知厨房
    pGirl->Notify();

    return 0;
}