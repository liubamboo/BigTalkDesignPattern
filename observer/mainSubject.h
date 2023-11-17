#ifndef _MAINSUBJECT_H_
#define _MAINSUBJECT_H_

#include "subject.h"
#include "delegateNonParams.h"

/*
 * CBoss 通知者将通知事件委托给了 CIEvent
 */
class CBoss : public CISubject
{
public:
    void Notify() override
    {
        Event();
    }
public:
    CIEvent Event;
};

/*
 * CSecretary 通知者将通知事件委托给了 CIEvent
 */
class CSecretary : public CISubject
{
public:
    void Notify() override
    {
        Event();
    }
public:
    CIEvent Event;

};
#endif // _MAINSUBJECT_H_