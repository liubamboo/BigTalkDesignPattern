#include <iostream>
#include <list>

using namespace std;

class Context
{
private:
    string input;
    string output;
public:
    string GetInput()
    {
        return input;
    }
    void SetInput(string s)
    {
        input = s;
    }

    string GetOutput()
    {
        return output;
    }
    void SetOutput(string s)
    {
        output = s;
    }
};

class AbstractExpression
{
public:
    virtual void Interpret(Context *context) = 0;
    virtual ~AbstractExpression()
    {

    }
};

class TerminalExpression : public AbstractExpression
{
public:
    void Interpret(Context *context) override
    {
        cout << "终端解释器" << endl;
    }
};

class NonterminalExpression : public AbstractExpression
{
public:
    void Interpret(Context *context)
    {
        cout << "非终端解释器" << endl;
    }
};

int main()
{
    Context *context = new Context();
    list<AbstractExpression*> expressions;

    expressions.push_front(new TerminalExpression);
    expressions.push_front(new NonterminalExpression);
    expressions.push_front(new TerminalExpression);
    expressions.push_front(new TerminalExpression);

    for (auto l : expressions)
    {
        l->Interpret(context);
    }

    return 0;
}