#ifndef BRAVE_H_
#define BRAVE_H_

#include "BattleCharacter.hpp"
#include <iostream>

class Brave : public BattleCharacter
{
public:
    Brave(string name, ability_t hp, ability_t mp, ability_t attack, ability_t defense, ability_t speed)
        : BattleCharacter(name, hp, mp, attack, defense, speed) {}
    ~Brave() {}

    void Action(BattleCharacter* enemy)
    {
        Attack(enemy);
    }

    void DiePrint()
    {
        std::cout << "ゆうしゃはしんでしまった！" << std::endl;
    }
};

#endif // !BRAVE_H_
