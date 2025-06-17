#include "BattleCharacter.hpp"
#include "StateOperation.hpp"

void BattleCharacter::Turn(BattleCharacter& other)
{
    UnDefense();

    if (StateOperation::IsState(*this, State::PARALYSIS)
        || StateOperation::IsState(*this, State::SLEEP)) {
        std::cout << "行動不能" << std::endl;
    } else {
        Action(other);
    }

    if (StateOperation::IsState(*this, State::POISON)) {
        PoisonDamage();
    }

    if (IsDie()) {
        // ここでどうバトルの終了を呼び出し元に通知するか？
    }
}