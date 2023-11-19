#include <iostream>
#include <string>

using namespace std;

/*
 * 使用了抽象工厂模式的数据访问程序
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

class Department
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
        return deptName;
    }
    void SetName(string name)
    {
        deptName = name;
    }
private:
    int id;
    string deptName;
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

class IDepartment
{
public:
    virtual void Insert(Department *pDepartment) = 0;
    virtual Department* GetDepartment(int id) = 0;
};

class SqlserverDepartment : public IDepartment
{
public:
    void Insert(Department* pDept) override
    {
        cout << "在Sqlserver中给Department表增加一条记录" << endl;
    }

    Department* GetDepartment(int id) override
    {
        cout << "在Sqlserver中根据ID得到Department表一条记录" << endl;
        return nullptr;
    }
};

class AccessDepartment : public IDepartment
{
public:
    void Insert(Department *pDept) override
    {
        cout << "在Access中给Department表增加一条记录" << endl;
    }

    Department* GetDepartment(int id) override
    {
        cout << "在Access中根据ID得到Department表一条记录" << endl;
        return nullptr;
    }
};

class IFactory
{
public:
    virtual IUser* CreateUser() = 0;
    virtual IDepartment* CreateDepartment() = 0;
};

class SqlServerFactory : public IFactory
{
public:
    IUser* CreateUser() override
    {
        return new SqlserverUser();
    }

    IDepartment* CreateDepartment() override
    {
        return new SqlserverDepartment();
    }
};

class AccessFactory : public IFactory
{
public:
    IUser* CreateUser() override
    {
        return new AccessUser();
    }

    IDepartment* CreateDepartment() override
    {
        return new AccessDepartment();
    }
};

int main()
{
    User *pUser = new User();
    Department *pDept = new Department();

    IFactory *pFactory = new AccessFactory();

    IUser *pIu = pFactory->CreateUser();
    pIu->Insert(pUser);
    pIu->GetUser(1);

    IDepartment *pId = pFactory->CreateDepartment();
    pId->Insert(pDept);
    pId->GetDepartment(1);
    
    return 0;
}