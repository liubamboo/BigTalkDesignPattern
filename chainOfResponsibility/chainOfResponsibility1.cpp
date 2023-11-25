#include <iostream>
#include <string>

using namespace std;

enum ManagerLevel
{
    Jingli,
    Zongjian,
    Zongjingli
};

class Request
{
private:
    string type;
    string content;
    int number;
public:
    string GetType()
    {
        return type;
    }
    void SetType(string type)
    {
        this->type = type;
    }

    string GetContent()
    {
        return content;
    }
    void SetContent(string content)
    {
        this->content = content;
    }

    int GetNumber()
    {
        return number;
    }
    void SetNumber(int number)
    {
        this->number = number;
    }
};

class Manager
{
protected:
    string name;
public:
    Manager(string name) : name(name) {}

    void GetResult(ManagerLevel managerLevel, Request *pRequest)
    {
        if (managerLevel == ManagerLevel::Jingli)
        {
            if (pRequest->GetType() == "请假" && pRequest->GetNumber() <= 2)
            {
                cout << name << ":" << pRequest->GetContent() << " 数量：" << pRequest->GetNumber() << "被批准" << endl;
            }
            else
            {
                cout << name << ":" << pRequest->GetContent() << " 数量：" << pRequest->GetNumber() << "我无权处理" << endl;
            }
        }
        else if (managerLevel == ManagerLevel::Zongjian)
        {
            if (pRequest->GetType() == "请假" && pRequest->GetNumber() <= 5)
            {
                cout << name << ":" << pRequest->GetContent() << " 数量：" << pRequest->GetNumber() << " 被批准" << endl;
            }
            else
            {
                cout << name << ":" << pRequest->GetContent() << " 数量：" << pRequest->GetNumber() << " 我无权处理" << endl;
            }
        }
        else if (managerLevel == ManagerLevel::Zongjingli)
        {
            if (pRequest->GetType() == "请假")
            {
                cout << name << ":" << pRequest->GetContent() << " 数量：" << pRequest->GetNumber() << " 被批准" << endl;
            }
            else if (pRequest->GetType() == "加薪" && pRequest->GetNumber() <= 500)
            {
                cout << name << ":" << pRequest->GetContent() << " 数量：" << pRequest->GetNumber() << " 被批准" << endl;
            }
            else if (pRequest->GetType() == "加薪" && pRequest->GetNumber() > 500)
            {
                cout << name << ":" << pRequest->GetContent() << " 数量：" << pRequest->GetNumber() << " 再说吧" << endl;
            }
        }
    }
};

int main()
{
    Manager *pJinli = new Manager("金利");
    Manager *pZongjian = new Manager("宗剑");
    Manager *pZongjingli = new Manager("钟精励");

    Request *pRequest = new Request();
    pRequest->SetType("加薪");
    pRequest->SetContent("小菜请求加薪");
    pRequest->SetNumber(1000);

    pJinli->GetResult(ManagerLevel::Jingli, pRequest);
    pZongjian->GetResult(ManagerLevel::Zongjian, pRequest);
    pZongjingli->GetResult(ManagerLevel::Zongjingli, pRequest);

    Request *pRequest2 = new Request();
    pRequest2->SetType("请假");
    pRequest2->SetContent("小菜请假");
    pRequest2->SetNumber(3);

    pJinli->GetResult(ManagerLevel::Jingli, pRequest2);
    pZongjian->GetResult(ManagerLevel::Zongjian, pRequest2);
    pZongjingli->GetResult(ManagerLevel::Zongjingli, pRequest2);

    return 0;
}