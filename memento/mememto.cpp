#include <iostream>


using namespace std;

class RoleStateMememto
{
private:
    int vitality;
    int attack;
    int defense;
public:
    RoleStateMememto(int vit, int atk, int def) :
        vitality(vit), attack(atk), defense(def)
    {}

    int GetVitality() const
    {
        return vitality;
    }
    void SetVitality(int value)
    {
        vitality = value;
    }

    int GetAttack() const
    {
        return attack;
    }
    void SetAttack(int value)
    {
        attack = value;
    }

    int GetDefense() const
    {
        return defense;
    }
    void SetDefense(int value)
    {
        defense = value;
    }
};

class GameRole
{
private:
    int vitality; //生命值
    int attack;  //攻击力
    int defense; //防御力
public:
    int GetVitality()
    {
        return vitality;
    }
    void SetVitality(int value)
    {
        vitality = value;
    }

    int GetAttack()
    {
        return attack;
    }
    void SetAttack(int value)
    {
        attack = value;
    }

    int GetDefense()
    {
        return defense;
    }
    void SetDefense(int value)
    {
        defense = value;
    }

    void StateDisplay()
    {
        cout << "角色当前状态：" << endl;
        cout << "体力：" << vitality << endl;
        cout << "攻击力：" << attack << endl;
        cout << "防御力：" << defense << endl;
    }
    // 保存角色状态
    RoleStateMememto* SaveState()
    {
        return (new RoleStateMememto(vitality, attack, defense));
    }
    // 恢复角色状态
    void RecoveryState(RoleStateMememto *pMemento)
    {
        vitality = pMemento->GetVitality();
        attack   = pMemento->GetAttack();
        defense  = pMemento->GetDefense();
    }

    // 获得初始状态
    void GetInitState()
    {
        vitality = 100;
        attack   = 100;
        defense  = 100;
    }

    // 战斗
    void Fight()
    {
        vitality = 0;
        attack   = 0;
        defense  = 0;
    }

};

class RoleStateCaretaker
{
private:
    RoleStateMememto *pMemeto;
public:
    RoleStateMememto* GetMememto()
    {
        return pMemeto;
    }
    void SetMememto(RoleStateMememto* pVal)
    {
        pMemeto = pVal;
    }
};

int main()
{
    // 大战Boss前
    GameRole *pLixiaoyao = new GameRole();
    pLixiaoyao->GetInitState();
    pLixiaoyao->StateDisplay();

    // 保存进度
    RoleStateCaretaker *pStateAdmin = new RoleStateCaretaker();
    pStateAdmin->SetMememto(pLixiaoyao->SaveState());

    // 大战Boss时，耗损严重
    pLixiaoyao->Fight();
    pLixiaoyao->StateDisplay();

    // 恢复之前的状态
    pLixiaoyao->RecoveryState(pStateAdmin->GetMememto());
    pLixiaoyao->StateDisplay();

    return 0;
}