#ifndef STATE_H_
#define STATE_H_

#include "BattleCharacter.hpp"
#include "Abnormal.hpp"

class State
{
public:
    static void SetState(BattleCharacter& target, Abnormal abnormal)
    {
        target.SetState((target.GetState() | abnormal));
    }

    static void RemoveState(BattleCharacter& target, Abnormal abnormal)
    {
        target.SetState((target.GetState() & ~abnormal));
    }

    static void SetNormal(BattleCharacter& target)
    {
        target.SetState(Abnormal::NORMAL);
    }

    static bool IsState(BattleCharacter& target, Abnormal abnormal)
    {
        return (target.GetState() & abnormal) == abnormal;
    }

    static bool IsNormal(BattleCharacter& target)
    {
        return target.GetState() == Abnormal::NORMAL;
    }
};

#endif // !STATE_H_
