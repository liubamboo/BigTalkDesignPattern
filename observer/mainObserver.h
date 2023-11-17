#ifndef _MAINOBSERVER_H_
#define _MAINOBSERVER_H_

#include "subject.h"
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

/*
 * 股票观察者
 */
class CStockObserver
{
public:
    CStockObserver(CISubject *subject, string name) : subject(subject), name(name) {}
    void CloseMarket()
    {
        cout << subject->State() << "," << name << "关闭股市行情，认真工作" << endl;
    }
private:
    CISubject *subject;
    string name;
};

class CNBAObserver
{
public:
    CNBAObserver(CISubject *subject, string name) : subject(subject), name(name) {}
    void CloseNBA()
    {
        cout << subject->State() << "," << name << "关闭NBA直播,认真工作" << endl;
    }
private:
    CISubject *subject;
    string name;
};

#endif // _MAINOBSERVER_H_