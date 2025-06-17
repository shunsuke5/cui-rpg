#include "StateOperation.hpp"
#include "BattleCharacter.hpp"

void StateOperation::SetState(BattleCharacter* target, State abnormal)
{
    target->SetState((target->GetState() | abnormal));
}

void StateOperation::RemoveState(BattleCharacter* target, State abnormal)
{
    target->SetState((target->GetState() & ~abnormal));
}

void StateOperation::SetNormal(BattleCharacter* target)
{
    target->SetState(State::NORMAL);
}

bool StateOperation::IsState(const BattleCharacter* target, State abnormal)
{
    return (target->GetState() & abnormal) == abnormal;
}

bool StateOperation::IsNormal(const BattleCharacter* target)
{
    return target->GetState() == State::NORMAL;
}