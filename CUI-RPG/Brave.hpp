#ifndef BRAVE_H_
#define BRAVE_H_

#include "BattleCharacter.hpp"
#include <iostream>
#include <map>

class Brave : public BattleCharacter
{
public:
    using level_t = unsigned short;
    using exp_t = unsigned short;
    using map = std::map<level_t, exp_t>;

    Brave(string name, ability_t hp, ability_t mp, ability_t attack, ability_t defense, ability_t speed)
        : BattleCharacter(name, hp, mp, attack, defense, speed)
    {
        m_level = 1;
        m_exp = 0;

        m_levelToExp.insert(std::make_pair(2, 3));
        m_levelToExp.insert(std::make_pair(3, 5));
        m_levelToExp.insert(std::make_pair(4, 8));
        m_levelToExp.insert(std::make_pair(5, 15));
    }
    ~Brave() {}

    void Action(BattleCharacter* enemy)
    {
        int n = 0;
        std::cout << "1：こうげき　2：ぼうぎょ" << std::endl;
        std::cout << m_name << "はどうする？ > " << std::flush;
        std::cin >> n;

        // TODO: 想定外の値が入力されたときにループさせる例外処理を実装する
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

    bool IsLevelUp() { return m_exp >= m_levelToExp.at(m_level + 1); }

    void OnLevelUp(exp_t exp)
    {
        m_exp += exp;
        level_t beforeLevel = m_level;

        while (m_level != MAX_LEVEL && IsLevelUp()) {
            ++m_level;
        }

        int upLevel = m_level - beforeLevel;
        if (upLevel != 0) {
            std::cout << m_name << "のレベルが " << upLevel << " あがった！" << std::endl;
        }
    }

    void GameOver()
    {
        std::cout << m_name << "はしんでしまった！" << std::endl;
    }

private:
    const level_t MAX_LEVEL = 99;
    level_t m_level;
    exp_t m_exp;
    map m_levelToExp;
    // TODO: レベルに対応するステータス表をメンバとして実装する
};

#endif // !BRAVE_H_
