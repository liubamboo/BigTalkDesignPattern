#include <iostream>
#include <string>

using namespace std;

class TestPaper
{
public:
    void TestQuestion1()
    {
        cout << "杨过得到，后来给了郭靖，炼成倚天剑、屠龙刀的玄铁可能是[ ] a.球磨铸铁 b.马口铁 c.高速合金刚 d.碳素纤维" << endl;
        cout << "答案： " << Answer1() << endl;
    }

    void TestQuestion2()
    {
        cout << "杨过、程英、陆无双铲除了情花，造成[ ] a.使这种植物不再害人 b.使一种珍稀物种灭绝 c.破坏了那个生物圈的生态平衡 "
             << "d.造成该地区沙漠化  " << endl;
        cout << "答案： " << Answer2() << endl;
    }

    void TestQuestion3()
    {
        cout << "蓝凤凰的致使华山师徒、桃谷六仙呕吐不止,如果你是大夫,会给他们开什么药[ ] a.阿司匹林 b.牛黄解毒片 c.氟哌酸 "
             << "d.让他们喝大量的生牛奶 e.以上全不对   " << endl;
        cout << "答案： " << Answer3() << endl;
    }
protected:
    virtual string Answer1()
    {
        return "";
    }

    virtual string Answer2()
    {
        return "";
    }

    virtual string Answer3()
    {
        return "";
    }
};

class TestPaperA : public TestPaper
{
protected:
    string Answer1() override
    {
        return "b";
    }

    string Answer2() override
    {
        return "c";
    }

    string Answer3() override
    {
        return "a";
    }
};

class TestPaperB : public TestPaper
{
protected:
    string Answer1() override
    {
        return "c";
    }

    string Answer2() override
    {
        return "a";
    }

    string Answer3() override
    {
        return "a";
    }
};

int main()
{
    cout << "学生甲抄的试卷" << endl;
    TestPaper *pStudentA = new TestPaperA();
    pStudentA->TestQuestion1();
    pStudentA->TestQuestion2();
    pStudentA->TestQuestion3();

    cout << "学生乙抄的试卷" << endl;
    TestPaper *pStudentB = new TestPaperB();
    pStudentB->TestQuestion1();
    pStudentB->TestQuestion2();
    pStudentB->TestQuestion3();
    return 0;
}