#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T, typename U>
class Interator
{
public:
    typedef typename vector<T>::iterator iter_type;
    Interator(U *pData, bool reverse = false) : mPData(pData)
    {
        mIt = mPData->mData.begin();
    }

    void First()
    {
        mIt = mPData->mData.begin();
    }

    void Next()
    {
        mIt++;
    }

    bool IsDone()
    {
        return (mIt == mPData->mData.end());
    }

    iter_type Current()
    {
        return mIt;
    }
private:
    U *mPData;
    iter_type mIt;
};

template <class T>
class Container
{
private:
    friend class Interator<T, Container>;
    vector<T> mData;
public:
    void Add(T a)
    {
        mData.push_back(a);
    }

    Interator<T, Container> *CreateInterator()
    {
        return new Interator<T, Container>(this);
    }
};

// 自定义数据类型
class Data
{
private:
    int mData;
public:
    Data(int a = 0) : mData(a)
    {

    }

    void SetData(int a)
    {
        mData = a;
    }

    int data()
    {
        return mData;
    }
};

void ClientCode()
{
    cout << "----------------------------Interator with int-----------------------------" << endl;
    Container<int> cont;

    for (int i = 0; i < 10; i++)
    {
        cont.Add(i);
    }

    Interator<int, Container<int> > *it = cont.CreateInterator();
    for (it->First(); !it->IsDone(); it->Next())
    {
        cout << *it->Current() << endl;
    }

    cout << "----------------------------Interator with custom class-----------------------------" << endl;
    Container<Data> cont2;
    Data a(100), b(1000), c(10000);
    cont2.Add(a);
    cont2.Add(b);
    cont2.Add(c);

    Interator<Data, Container<Data> > *it2 = cont2.CreateInterator();
    for (it2->First(); !it2->IsDone(); it2->Next())
    {
        cout << it2->Current()->data() << endl;
    }

    delete it;
    delete it2;
}

int main()
{
    ClientCode();
    return 0;
}