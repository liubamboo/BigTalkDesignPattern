#include <iostream>

using namespace std;

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
    Manager *superior;
public:
    Manager(string name) : name(name) {}

    void SetSuperior(Manager *superior)
    {
        this->superior = superior;
    }

    virtual void RequestApplications(Request *pRequest) = 0;
    ~Manager() {}
};

class CommonManager : public Manager
{
public:
    CommonManager(string name) : Manager(name) {}

    void RequestApplications(Request *pRequest) override
    {
        if (pRequest->GetType() == "请假" && pRequest->GetNumber() <= 2)
        {
            cout << name << ":" << pRequest->GetContent() << " 数量: " << pRequest->GetNumber() << " 被批准" << endl;
        }
        else if (superior != nullptr)
        {
            superior->RequestApplications(pRequest);
        }
    }
};

class Majordomo : public Manager
{
public:
    Majordomo(string name) : Manager(name) {}

    void RequestApplications(Request *pRequest) override
    {
        if (pRequest->GetType() == "请假" && pRequest->GetNumber() <= 5)
        {
            cout << name << ":" << pRequest->GetContent() << " 数量: " << pRequest->GetNumber() << " 被批准" << endl;
        }
        else if (superior != nullptr)
        {
            superior->RequestApplications(pRequest);
        }
    }

};

class GeneralManager : public Manager
{
public:
    GeneralManager(string name) : Manager(name) {}

    void RequestApplications(Request *pRequest)
    {
        if (pRequest->GetType() == "请假")
        {
            cout << name << ":" << pRequest->GetContent() << " 数量: " << pRequest->GetNumber() << " 被批准" << endl;
        }
        else if (pRequest->GetType() == "加薪" && pRequest->GetNumber() <= 500)
        {
            cout << name << ":" << pRequest->GetContent() << " 数量: " << pRequest->GetNumber() << " 被批准" << endl;
        }
        else if (pRequest->GetType() == "加薪" && pRequest->GetNumber() > 500)
        {
            cout << name << ":" << pRequest->GetContent() << " 数量: " << pRequest->GetNumber() << " 再说吧" << endl;
        }
    }
};

int main()
{
    CommonManager *pJingli = new CommonManager("金利");
    Majordomo *pZongjian = new Majordomo("宗剑");
    GeneralManager *pZongjingli = new GeneralManager("钟精励");
    pJingli->SetSuperior(pZongjian);
    pZongjian->SetSuperior(pZongjingli);

    Request *pRequest = new Request();
    pRequest->SetType("请假");
    pRequest->SetContent("小菜请假");
    pRequest->SetNumber(1);
    pJingli->RequestApplications(pRequest);

    Request *pRequest2 = new Request();
    pRequest2->SetType("请假");
    pRequest2->SetContent("小菜请假");
    pRequest2->SetNumber(4);
    pJingli->RequestApplications(pRequest2);

    Request *pRequest3 = new Request();
    pRequest3->SetType("加薪");
    pRequest3->SetContent("小菜请求加薪");
    pRequest3->SetNumber(500);

    Request *pRequest4 = new Request();
    pRequest4->SetType("加薪");
    pRequest4->SetContent("小菜请求加薪");
    pRequest4->SetNumber(1000);
    pJingli->RequestApplications(pRequest4);

    delete pRequest4;
    delete pRequest3;
    delete pRequest2;
    delete pRequest;
    delete pZongjingli;
    delete pZongjian;
    delete pJingli;

    return 0;
}