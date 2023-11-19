#include <iostream>
#include <string>

using namespace std;

/*
 * 基本逻辑实现
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

class SqlserverUser
{
public:
    void Insert(User *pUser)
    {
        cout << "在Sqlserver中给User表增加一条记录" << endl;
    }

    User* GetUser(int id)
    {
        cout << "在Sqlserver中根据ID得到User表的一条记录" << endl;
        return nullptr;
    }
};

int main()
{
    User *pUser = new User();
    SqlserverUser *pSu = new SqlserverUser();

    pSu->Insert(pUser);
    pSu->GetUser(1);
    
    return 0;
}