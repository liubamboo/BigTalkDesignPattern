#include <iostream>
#include <string>

using namespace std;

class Player
{
protected:
    string name;
public:
    Player(string name) : name(name) {}
    virtual void Attack() = 0;
    virtual void Defense() = 0;
};

class Forwards : public Player
{
public:
    Forwards(string name) : Player(name) {}
    void Attack() override
    {
        cout << "前锋" << Player::name << "进攻" << endl;
    }
    void Defense() override
    {
        cout << "前锋" << Player::name << "防守" << endl;
    }
};

class Center : public Player
{
public:
    Center(string name) : Player(name) {}
    void Attack() override
    {
        cout << "中锋" << Player::name << "进攻" << endl;
    }

    void Defense() override
    {
        cout << "中锋" << Player::name << "防守" << endl;
    }
};

class Guards : public Player
{
public:
    Guards(string name) : Player(name) {}

    void Attack() override
    {
        cout << "后卫" << Player::name << "进攻" << endl;
    }

    void Defense() override
    {
        cout << "后卫" << Player::name << "防守" << endl;
    }
};

// 外籍中锋
class ForeignCenter
{
private:
    string name;
public:
    string GetName()
    {
        return name;
    }

    void SetName(string value)
    {
        name = value;
    }

    void JinGong()
    {
        cout << "外籍中锋" << name << "进攻" << endl;
    }

    void FangShou()
    {
        cout << "外籍中锋" << name << "防守" << endl;
    }
};

class Translator : public Player
{
private:
    ForeignCenter *pWjzf;
public:
    Translator(string name) : Player(name)
    {
        pWjzf = new ForeignCenter();
        pWjzf->SetName(name);
    }

    void Attack() override
    {
        pWjzf->JinGong();
    }

    void Defense() override
    {
        pWjzf->FangShou();
    }
};

int main()
{
    Player *pB = new Forwards("巴蒂尔");
    pB->Attack();

    Player *pM = new Guards("麦克格雷迪");
    pM->Attack();

    Player *pYm = new Translator("姚明");
    pYm->Attack();
    pYm->Defense();

    return 0;
}