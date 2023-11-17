#ifndef _SUBJECT_H_
#define _SUBJECT_H_
#include <string>
using std::string;

/*
 * 主题基类
 */
class CISubject
{
public:
    string State() const 
    {
        return state;
    }
    void State(string val)
    {
        state = val;
    }

    virtual void Notify() = 0;
private:
    string state;
};


#endif