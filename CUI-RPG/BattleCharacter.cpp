#include "BattleCharacter.hpp"
#include "StateOperation.hpp"

bool BattleCharacter::Turn(BattleCharacter* other)
{
    UnDefense();

    if (StateOperation::IsState(this, State::PARALYSIS)
        || StateOperation::IsState(this, State::SLEEP)) {
        std::cout << "行動不能" << std::endl;
    } else {
        Action(other);
    }

    if (StateOperation::IsState(this, State::POISON)) {
        PoisonDamage();
    }

    if (IsDie()) {
        DiePrint();
        return false;
    }

    return true;
}