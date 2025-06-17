#include "StateOperation.hpp"
#include "BattleCharacter.hpp"

void SetState(BattleCharacter& target, State abnormal)
{
    target.SetState((target.GetState() | abnormal));
}

void RemoveState(BattleCharacter& target, State abnormal)
{
    target.SetState((target.GetState() & ~abnormal));
}

void SetNormal(BattleCharacter& target)
{
    target.SetState(State::NORMAL);
}

bool IsState(BattleCharacter& target, State abnormal)
{
    return (target.GetState() & abnormal) == abnormal;
}

bool IsNormal(BattleCharacter& target)
{
    return target.GetState() == State::NORMAL;
}