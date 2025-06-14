#ifndef BATTLE_CHARACTER_H_
#define BATTLE_CHARACTER_H_

#include "Abnormal.hpp"

class BattleCharacter
{
public:
    virtual Abnormal& GetState() = 0;
};

#endif // !BATTLE_CHARACTER_H_
