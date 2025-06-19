#include "BattleCharacter.hpp"
#include "StateOperation.hpp"

bool BattleCharacter::Turn(BattleCharacter& other)
{
    if (IsDie()) { return false; }

    UnDefense();

    // TODO: 状態異常の名前も表示するように実装する
    if (StateOperation::IsState(*this, State::PARALYSIS)
        || StateOperation::IsState(*this, State::SLEEP)) {
        std::cout << "こうどうふのう" << std::endl;
    } else {
        Action(other);
    }

    if (StateOperation::IsState(*this, State::POISON)) {
        PoisonDamage();
    }

    return !IsDie();
}