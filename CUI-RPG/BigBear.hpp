#ifndef BIG_BEAR_H_
#define BIG_BEAR_H_

#include "Enemy.hpp"
#include "RandomNumGenerator.hpp"
#include <iostream>

class BigBear : public Enemy
{
public:
    BigBear(Brave& brave) : Enemy(brave, "おおぐま", 5, 0, 3, 3, 3, 10) {}

    void Action(BattleCharacter& brave)
    {
        int n = RandomNumGenerator::Generate(1, 3);
        if (n < 3) {
            Enemy::Action(m_braveRef, n);
        } else {
            std::cout << m_name << "はうでをふりまわした！" << std::endl;
        }
    }
};

#endif // !BIG_BEAR_H_
