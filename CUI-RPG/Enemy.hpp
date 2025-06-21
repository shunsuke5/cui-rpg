#ifndef ENEMY_H_
#define ENEMY_H_

#include "BattleCharacter.hpp"
#include "RandomNumGenerator.hpp"
#include <iostream>
#include <random>

class Enemy : public BattleCharacter
{
public:
    using exp_t = unsigned short;

    Enemy(Brave& brave, string name, ability_t hp, ability_t mp, ability_t attack, ability_t defense, ability_t speed, exp_t exp)
        : BattleCharacter(name, hp, mp, attack, defense, speed), m_braveRef(brave), m_exp(exp) {}
    ~Enemy() {}

    virtual void Action(BattleCharacter& brave, int n = 0)
    {
        if (n == 0) {
            n = RandomNumGenerator::Generate(1, 3);
        }

        switch (n) {
        case 1:
            Attack(brave);
            break;
        case 2:
            Defense();
            break;
        case 3:
            Escape();
            break;
        default:
            Attack(brave);
            break;
        }
    }

    void Encount()
    {
        std::cout << m_name << "があらわれた！" << std::endl;
    }

    void DiePrint()
    {
        std::cout << m_name << "をたおした！" << std::endl;
        std::cout << m_exp << " のけいけんちをかくとく！" << std::endl;
    }

    exp_t GetExp() { return m_exp; }

protected:
    Brave& m_braveRef;

private:
    exp_t m_exp;
};

#endif // !ENEMY_H_
