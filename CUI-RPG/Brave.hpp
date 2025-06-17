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
        int n = 0;
        std::cout << "1：こうげき　2：ぼうぎょ" << std::endl;
        std::cout << m_name << "はどうする？ > " << std::flush;
        std::cin >> n;

        switch (n) {
        case 1:
            Attack(enemy);
            break;
        case 2:
            Defense();
            break;
        default:
            break;
        }
    }

    void DiePrint()
    {
        std::cout << m_name << "はしんでしまった！" << std::endl;
    }
};

#endif // !BRAVE_H_
