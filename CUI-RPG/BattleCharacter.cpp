#include "BattleCharacter.hpp"

bool BattleCharacter::Turn(BattleCharacter& other)
{
    if (IsDie()) { return false; }

    UnDefense();
    InitIsEscape();

    // TODO: 状態異常の名前も表示するように実装する
    if (IsState(State::PARALYSIS) || IsState(State::SLEEP)) {
        std::cout << "こうどうふのう" << std::endl;
    } else {
        Action(other);
    }

    if (IsState(State::POISON)) {
        PoisonDamage();
    }

    return !IsDie() && !IsEscape();
}