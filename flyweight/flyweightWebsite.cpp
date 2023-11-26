#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class User
{
private:
    string name;
public:
    User(string name) : name(name)
    {

    }

    string GetName()
    {
        return name;
    }
};

class Website
{
public:
    virtual void Use(User *user) = 0;
    ~Website()
    {

    }
};

class ConcreteWebsite : public Website
{
private:
    string name;
public:
    ConcreteWebsite(string name) : name(name)
    {

    }

    void Use(User *pu) override
    {
        cout << "网站分类：" << name << " 用户：" << pu->GetName() << endl;
    }
};

class WebsiteFactory
{
private:
    unordered_map<string, Website*> flyweights;
public:
    Website* GetWebsiteCategory(string key)
    {
        if (flyweights.find(key) == flyweights.end())
        {
            flyweights[key] = new ConcreteWebsite(key);
        }

        return flyweights[key];
    }

    int GetWebsiteCount()
    {
        return flyweights.size();
    }
};

int main()
{
    WebsiteFactory *pf = new WebsiteFactory();

    Website *pfx = pf->GetWebsiteCategory("产品展示");
    pfx->Use(new User("小菜"));

    Website *pfy = pf->GetWebsiteCategory("产品展示");
    pfy->Use(new User("大鸟"));

    Website *pfz = pf->GetWebsiteCategory("产品展示");
    pfz->Use(new User("娇娇"));

    Website *pfl = pf->GetWebsiteCategory("博客");
    pfl->Use(new User("老顽童"));

    Website *pfm = pf->GetWebsiteCategory("博客");
    pfm->Use(new User("桃谷六仙"));

    Website *pfn = pf->GetWebsiteCategory("博客");
    pfn->Use(new User("南海鳄神"));

    cout << "得到网站分类总数：" << pf->GetWebsiteCount() << endl;
    return 0;
}