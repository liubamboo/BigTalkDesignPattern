#include <iostream>

using namespace std;

// 不能保证线程唯一
class Singleton
{
private:
    Singleton() {}
    ~Singleton() {}
public:
    static Singleton& getInstance()
    {
        static Singleton instance;
        return instance;
    }

    Singleton(const Singleton&) = delete;
    void operator=(const Singleton&) = delete;

    void printHello()
    {
        cout << "Hello" << endl;
    }
};

int main()
{
    Singleton &ps = Singleton::getInstance();
    ps.printHello();
    return 0;
}