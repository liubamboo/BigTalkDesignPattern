#ifndef _DELEGATE_H_
#define _DELEGATE_H_

#include <list>
using std::list;

/*
 * 带1个参数的委托机制实现
 */

template<class ArgsType>
class IDelegate
{
public:
    virtual void Notify(ArgsType args) = 0;
};

template<class ObserverType, class ArgsType>
class IDelegateAgent : public IDelegate<ArgsType>
{
    typedef void (ObserverType::*Handler)(ArgsType args);
public:
    IDelegateAgent(ObserverType *type, Handler handler) : type(type), handler(handler) {}

    void Notify(ArgsType args) override
    {
        (type->*handler)(args);
    }
private:
    Handler handler;
    ObserverType *type;
};

template<class ArgsType>
class CIEvent
{
public:
    void operator+= (IDelegate<ArgsType> &delegate)
    {
        myList.push_front(delegate);
    }

    void operator-= (IDelegate<ArgsType> &delegate)
    {
        myList.remove(delegate);
    }

    void operator() (ArgsType args)
    {
        for (auto item : myList)
        {
            item->Notify(args);
        }
    }
private:
    list<IDelegate<ArgsType>> myList;
};

#endif // _DELEGATE_H_