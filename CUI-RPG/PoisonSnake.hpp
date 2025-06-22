#ifndef POISON_SNAKE_H_
#define POISON_SNAKE_H_

#include "Enemy.hpp"
#include "RandomNumGenerator.hpp"
#include <iostream>
#include <string>

class PoisonSnake : public Enemy
{
public:
    PoisonSnake(Brave& brave, string name, ability_t hp,
        ability_t mp, ability_t attack, ability_t defense,
        ability_t speed, exp_t exp)
        : Enemy(brave, name, hp, mp, attack, defense, speed, exp) {
    }

    void Action(BattleCharacter& brave)
    {
        int n = RandomNumGenerator::FromOneToMax(BASE_ACTION_COUNT + 1);
        if (n < BASE_ACTION_COUNT) {
            Enemy::Action(m_braveRef, n);
        } else {
            std::cout << m_name << "はどくのきばでかみついた！" << std::endl;
            brave.SetState(State::POISON);
        }
    }
};

#endif // !POISON_SNAKE_H_
