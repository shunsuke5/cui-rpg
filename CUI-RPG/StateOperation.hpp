#ifndef STATE_H_
#define STATE_H_

#include "State.hpp"

class BattleCharacter;

class StateOperation
{
public:
    static void SetState(BattleCharacter* target, State abnormal);

    static void RemoveState(BattleCharacter* target, State abnormal);

    static void SetNormal(BattleCharacter* target);

    static bool IsState(const BattleCharacter* target, State abnormal);

    static bool IsNormal(const BattleCharacter* target);
};

#endif // !STATE_H_
