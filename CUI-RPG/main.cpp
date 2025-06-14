#include "PrintCoordinate.hpp"
#include <iostream>
#include <vector>
using namespace std;

class BattleCharacter
{
public:
    virtual int* GetState() = 0;
};

enum Abnormal
{
    NORMAL,
    POISON,     // 00000001
    PARALYSIS,  // 00000010
    SLEEP = 4,  // 00000100
};

class AbnormalState
{
public:
    static void SetState(BattleCharacter& target, int abnormal) { *target.GetState() |= abnormal; }
    static void RemoveState(BattleCharacter& target, int abnormal) { *target.GetState() &= ~abnormal; }
    static bool IsState(BattleCharacter& target, int abnormal) { return (*target.GetState() & abnormal) == abnormal; }
    static bool IsNormal(BattleCharacter& target) { return *target.GetState() == 0; }
};

class Brave : public BattleCharacter
{

public:
    Brave() : m_abnormalStatus(NORMAL) {}
    int* GetState() { return &m_abnormalStatus; }

    void CurrentStatus()
    {
        if (AbnormalState::IsNormal(*this)) {
            cout << "通常" << endl;
        }

        if (AbnormalState::IsState(*this, POISON)) {
            cout << "毒" << endl;
        }

        if (AbnormalState::IsState(*this, PARALYSIS)) {
            cout << "麻痺" << endl;
        }

        if (AbnormalState::IsState(*this, SLEEP)) {
            cout << "睡眠" << endl;
        }

        cout << endl;
    }

private:
    int m_abnormalStatus;
};

int main()
{
    Brave brave;
    brave.CurrentStatus();

    AbnormalState::SetState(brave, POISON);
    brave.CurrentStatus();

    AbnormalState::SetState(brave, PARALYSIS);
    brave.CurrentStatus();

    AbnormalState::RemoveState(brave, POISON);
    AbnormalState::SetState(brave, SLEEP);
    brave.CurrentStatus();
}