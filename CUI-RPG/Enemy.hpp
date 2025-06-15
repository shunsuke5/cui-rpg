#ifndef ENEMY_H_
#define ENEMY_H_

#include "BattleCharacter.hpp"

class Enemy : public BattleCharacter
{
public:
    Enemy(string name, ability_t hp, ability_t mp, ability_t attack, ability_t defense, ability_t speed)
        : BattleCharacter(name, hp, mp, attack, defense, speed) {}
    ~Enemy() {}
};

#endif // !ENEMY_H_
