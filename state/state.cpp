#include <iostream>

using namespace std;

class ForenoonState;
class Work;

class State
{
public:
    virtual void WriteProgram(Work* pW) = 0;
};


class Work
{
private:
    State *pCurrent;
    double hour;
    bool finish;
public:
    Work(State *pState)
    {
        pCurrent = pState;
    }

    double GetHour()
    {
        return hour;
    }

    void SetHour(double value)
    {
        hour = value;
    }

    bool GetTaskFinished()
    {
        return finish;
    }

    void SetTaskFinished(bool value)
    {
        finish = value;
    }

    void SetState(State *pS)
    {
        pCurrent = pS;
    }

    void WriteProgram()
    {
        pCurrent->WriteProgram(this);
    }
};

class SleepingState : public State
{
public:
    void WriteProgram(Work *pW) override
    {
        cout << "当前时间：" << pW->GetHour() << "点 不行了，睡着了" << endl;
    }
};

class RestState : public State
{
public:
    void WriteProgram(Work *pW) override
    {
        cout << "当前时间： " << pW->GetHour() << "点 下班回家了" << endl;
    }
};

class EveningState : public State
{
public:
    void WriteProgram(Work *pW) override
    {
        if (pW->GetTaskFinished())
        {
            pW->SetState(new RestState);
            pW->WriteProgram();
        }
        else
        {
            if (pW->GetHour() < 21)
            {
                cout << "当前时间：" << pW->GetHour() << "点 加班哦，疲累之极" << endl;
            }
            else
            {
                pW->SetState(new SleepingState);
                pW->WriteProgram();
            }
        }
    }
};

class AfternoonState : public State
{
public:
    void WriteProgram(Work* pW) override
    {
        if (pW->GetHour() < 17)
        {
            cout << "当前时间：" << pW->GetHour() << "点 下午状态还不错，继续努力" << endl;
        }
        else
        {
            pW->SetState(new EveningState);
            pW->WriteProgram();
        }
    }
};

class NoonState : public State
{
public:
    void WriteProgram(Work *pW) override
    {
        if (pW->GetHour() < 13)
        {
            cout << "当前时间：" << pW->GetHour() << "点 饿了，午饭；犯困，午休。" << endl;
        }
        else
        {
            pW->SetState(new AfternoonState);
            pW->WriteProgram();
        }
    }
};

class ForenoonState : public State
{
public:
    void WriteProgram(Work* pW) override
    {
        if (pW->GetHour() < 12)
        {
            cout << "当前时间：" << pW->GetHour() << "点 上午工作，精神百倍" << endl;
        }
        else
        {
            pW->SetState(new NoonState);
            pW->WriteProgram();
        }
    }
};

int main()
{
    Work *pEmergencyProjects = new Work(new ForenoonState());
    pEmergencyProjects->SetHour(9);
    pEmergencyProjects->WriteProgram();
    pEmergencyProjects->SetHour(10);
    pEmergencyProjects->WriteProgram();
    pEmergencyProjects->SetHour(12);
    pEmergencyProjects->WriteProgram();
    pEmergencyProjects->SetHour(13);
    pEmergencyProjects->WriteProgram();
    pEmergencyProjects->SetHour(14);
    pEmergencyProjects->WriteProgram();
    pEmergencyProjects->SetHour(17);
    pEmergencyProjects->WriteProgram();

    pEmergencyProjects->SetTaskFinished(false);
    pEmergencyProjects->WriteProgram();
    pEmergencyProjects->SetHour(19);
    pEmergencyProjects->WriteProgram();
    pEmergencyProjects->SetHour(22);
    pEmergencyProjects->WriteProgram();
    return 0;
}