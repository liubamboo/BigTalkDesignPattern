#include <iostream>

using namespace std;

class HandsetSoft
{
public:
    virtual void Run() {}
    ~HandsetSoft() {}
};

class HandsetBrand
{
protected:
    HandsetSoft *pSoft;
public:
    void SetHandsetSoft(HandsetSoft* pSoft)
    {
        this->pSoft = pSoft;
    }

    virtual void Run() = 0;
    virtual ~HandsetBrand() {}
};

class HandsetBrandN : public HandsetBrand
{
public:
    void Run() override
    {
        pSoft->Run();
    }
};

class HandsetBrandM : public HandsetBrand
{
public:
    void Run() override
    {
        pSoft->Run();
    }
};

class HandsetAddressList : public HandsetSoft
{
public:
    void Run() override
    {
        cout << "运行手机通讯录" << endl;
    }
};

class HandsetMP3 : public HandsetSoft
{
public:
    void Run() override
    {
        cout << "播放手机MP3" << endl;
    }
};

class HandsetGame : public HandsetSoft
{
public:
    void Run() override
    {
        cout << "运行手机游戏" << endl;
    }
};

int main()
{
    HandsetBrand *pAb = new HandsetBrandN();

    pAb->SetHandsetSoft(new HandsetGame());
    pAb->Run();

    pAb->SetHandsetSoft(new HandsetAddressList());
    pAb->Run();

    pAb = new HandsetBrandM();

    pAb->SetHandsetSoft(new HandsetGame());
    pAb->Run();

    pAb->SetHandsetSoft(new HandsetAddressList());
    pAb->Run();

    return 0;
}