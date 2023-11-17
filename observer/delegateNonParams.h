#ifndef _DELEGATENONPARAMS_H_
#define _DELEGATENONPARAMS_H_

#include<list>

using std::list;

/*
 * 不带参数的委托机制实现
 */

class IDelegate
{
public:
    virtual void Notify() = 0;
};

template<class ObserverType>
class IDelegateAgent : public IDelegate
{
    //typedef void (ObserverType::*Handler)(void);
    using Handler = void(ObserverType::*)();
public:
    IDelegateAgent(ObserverType *type, Handler handler)
    {
        this->handler = handler;
        this->type    = type;
    }

    void Notify() override
    {
        (type->*handler)();
    }
private:
    Handler handler;
    ObserverType *type;
};


class CIEvent
{
public:
    void operator+= (IDelegate *delegate)
    {
        myList.push_front(delegate);
    }

    void operator-= (IDelegate *delegate)
    {
        myList.remove(delegate);
    }

    void operator() ()
    {
        for (auto item : myList)
        {
            item->Notify();
        }
    }

private:
    list<IDelegate*> myList;
};

#endif // _DELEGATENONPARAMS_H_