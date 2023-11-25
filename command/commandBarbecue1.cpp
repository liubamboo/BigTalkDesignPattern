#include <iostream>

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
        cout << "烤鸡翅!" << endl;
    }
};

class Command
{
protected:
    Barbecuer *pReceiver;
public:
    Command(Barbecuer *pReceiver)
    {
        this->pReceiver = pReceiver;
    }

    virtual void ExecuteCommand() = 0;
    ~Command() {}
};

class BakeChickenWingCommand : public Command
{
public:
    BakeChickenWingCommand(Barbecuer *pReceiver) : Command(pReceiver) {}
    void ExecuteCommand() override
    {
        pReceiver->BakeChickenWing();
    }
};

class BakeMuttonCommand : public Command
{
public:
    BakeMuttonCommand(Barbecuer *pReceiver) : Command(pReceiver) {}

    void ExecuteCommand()
    {
        pReceiver->BakeMutton();
    }
};

class Waiter
{
private:
    Command *pCommand;
public:
    void SetOrder(Command *pCommand)
    {
        this->pCommand = pCommand;
    }

    void Notify()
    {
        pCommand->ExecuteCommand();
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

    // 开门营业
    pGirl->SetOrder(pBakeMuttonCommand1);
    pGirl->Notify();
    pGirl->SetOrder(pBakeMuttonCommand2);
    pGirl->Notify();
    pGirl->SetOrder(pBakeChickenWingCommand1);
    pGirl->Notify();

    return 0;
}