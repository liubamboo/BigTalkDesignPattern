#include <iostream>

using namespace std;


// 不能保证线程唯一
class Singleton
{
private:
    Singleton() {}
    ~Singleton() {}
    static Singleton instance;
public:
    static Singleton& getInstance()
    {
        return instance;
    }

    Singleton(const Singleton&) = delete;
    void operator=(const Singleton&) = delete;

    void printHello()
    {
        cout << "Hello" << endl;
    }
};

// 需要类外初始化
Singleton Singleton::instance;

int main()
{
    Singleton &ps = Singleton::getInstance();
    ps.printHello();
    return 0;
}