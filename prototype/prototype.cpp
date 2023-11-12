#include <iostream>
#include <string>

using namespace std;

class ICloneable
{
public:
    virtual ICloneable* Clone() const = 0;
    virtual ~ICloneable() {}
};

class WorkExperience : public ICloneable
{
private:
    string workDate;
    string company;
public:
    string GetWorkDate() const
    {
        return workDate;
    }

    void SetWorkDate(string workDate)
    {
        this->workDate = workDate;
    }

    string GetCompany()
    {
        return company;
    }

    void SetCompany(string company)
    {
        this->company = company;
    }

    WorkExperience() {}
    WorkExperience(string workDate, string company)
    {
        this->workDate = workDate;
        this->company = company;
    }
    virtual ICloneable* Clone()  const override 
    {
        return new WorkExperience(this->workDate, this->company);
    }

};

class Resume : public ICloneable
{
private:
    string name;
    string sex;
    string age;
    WorkExperience* pWork;
    Resume(WorkExperience *pWork)
    {
        this->pWork = dynamic_cast<WorkExperience*>(pWork->Clone());
    }
public:
    Resume(string name)
    {
        this->name = name;
        pWork = new WorkExperience();
    }

    void SetPersonalInfo(string sex, string age)
    {
        this->sex = sex;
        this->age = age;
    }

    void SetWorkExperience(string workDate, string company)
    {
        pWork->SetWorkDate(workDate);
        pWork->SetCompany(company);
    }

    void Display()
    {
        cout << this->name << " " << this->sex << " " << this->age << endl;
        cout << "工作经历 " <<  pWork->GetWorkDate() << " " << pWork->GetCompany() << endl;
    }

    ICloneable* Clone() const override
    {
        Resume* pResume = new Resume(this->pWork);
        pResume->name = this->name;
        pResume->sex = this->sex;
        pResume->age = this->age;
        return pResume;
    }
};

int main()
{
    Resume* pa = new Resume("大鸟");
    pa->SetPersonalInfo("男", "29");
    pa->SetWorkExperience("1998-2000", "XX公司");

    Resume* pb = dynamic_cast<Resume*>(pa->Clone());
    pb->SetWorkExperience("1998-2006", "YY企业");

    Resume* pc = dynamic_cast<Resume*>(pa->Clone());
    pc->SetWorkExperience("1998-2003", "ZZ企业");

    pa->Display();
    pb->Display();
    pc->Display();

    return 0;
}