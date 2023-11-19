#include <iostream>
#include <string>

using namespace std;

/*
 * 使用了工厂方法模式的数据访问程序
 */


class User
{
public:
    int GetId() const
    {
        return id;
    }
    void SetId(int id)
    {
        this->id = id;
    }
    string GetName() const
    {
        return name;
    }
    void SetName(string name)
    {
        this->name = name;
    }
private:
    int id;
    string name;
};


// user接口，解除user和数据库的具体耦合
class IUser
{
public:
    virtual void Insert(User *pUser) = 0;
    virtual User* GetUser(int id) = 0;
};

class SqlserverUser : public IUser
{
public:
    void Insert(User *pUser) override
    {
        cout << "在Sqlserver中给User表增加一条记录" << endl;
    }
    User* GetUser(int id) override
    {
        cout << "在Sqlserver中根据ID得到User表一条记录" << endl;
        return nullptr;
    }
};

class AccessUser : public IUser
{
    void Insert(User *pUser)
    {
        cout << "在Access中给User增加一条记录" << endl;
    }

    User* GetUser(int id)
    {
        cout << "在Access中根据ID得到User表一条记录" << endl;
        return nullptr;
    }
};

class IFactory
{
public:
    virtual IUser* CreateUser() = 0;
};


class SqlServerFactory : public IFactory
{
public:
    IUser* CreateUser() override
    {
        return new SqlserverUser();
    }
};

class AccessFactory : public IFactory
{
public:
    IUser* CreateUser() override
    {
        return new AccessUser();
    }
};


int main()
{
    User *pUser = new User();
    IFactory *pFactory = new AccessFactory();
    IUser *pIu = pFactory->CreateUser();

    pIu->Insert(pUser);
    pIu->GetUser(1);
    
    return 0;
}