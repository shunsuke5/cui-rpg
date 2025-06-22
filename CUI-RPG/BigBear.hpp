#ifndef BIG_BEAR_H_
#define BIG_BEAR_H_

#include "Enemy.hpp"
#include "RandomNumGenerator.hpp"
#include <iostream>
#include <string>

class BigBear : public Enemy
{
public:
    BigBear(Brave& brave, string name, ability_t hp,
        ability_t mp, ability_t attack, ability_t defense,
        ability_t speed, exp_t exp)
        : Enemy(brave, name, hp, mp, attack, defense, speed, exp) {
    }

    void Action(BattleCharacter& brave)
    {
        int n = RandomNumGenerator::Generate(1, 4);
        if (n <= BASE_ACTION_COUNT) {
            Enemy::Action(m_braveRef, n);
        } else {
            std::cout << m_name << "はうでをふりまわした！" << std::endl;
        }
    }
};

#endif // !BIG_BEAR_H_
