#include <iostream>

using namespace std;

class Receiver
{
public:
    void Action()
    {
        cout << "执行请求!" << endl;
    }
};

class Command
{
protected:
    Receiver *pReceiver;
public:
    Command(Receiver *pr) : pReceiver(pr){}
    virtual void Execute() = 0;
};

class ConcreteCommand : public Command
{
public:
    ConcreteCommand(Receiver *pr) : Command(pr) {}

    void Execute() override
    {
        pReceiver->Action();
    }
};

class Invoker
{
private:
    Command *pCommand;
public:
    void SetCommand(Command *pCommand)
    {
        this->pCommand = pCommand;
    }

    void ExecuteCommand()
    {
        pCommand->Execute();
    }
};

int main()
{
    Receiver *pr = new Receiver();
    Command *pc = new ConcreteCommand(pr);
    Invoker *pi = new Invoker();

    pi->SetCommand(pc);
    pi->ExecuteCommand();

    return 0;
}