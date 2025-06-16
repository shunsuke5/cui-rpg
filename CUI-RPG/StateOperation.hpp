#ifndef STATE_H_
#define STATE_H_

#include "State.hpp"

class BattleCharacter;

class StateOperation
{
public:
    static void SetState(BattleCharacter& target, State abnormal)
    {
        target.SetState((target.GetState() | abnormal));
    }

    static void RemoveState(BattleCharacter& target, State abnormal)
    {
        target.SetState((target.GetState() & ~abnormal));
    }

    static void SetNormal(BattleCharacter& target)
    {
        target.SetState(State::NORMAL);
    }

    static bool IsState(BattleCharacter& target, State abnormal)
    {
        return (target.GetState() & abnormal) == abnormal;
    }

    static bool IsNormal(BattleCharacter& target)
    {
        return target.GetState() == State::NORMAL;
    }
};

#endif // !STATE_H_
