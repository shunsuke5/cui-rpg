#ifndef BRAVE_H_
#define BRAVE_H_

#include "BattleCharacter.hpp"
#include <iostream>
#include <limits>
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

        m_levelToExp = GenerateLevelToExp();
    }
    ~Brave() {}

    static map GenerateLevelToExp();

    void Action(BattleCharacter& enemy);

    bool IsLevelUp() { return m_exp >= m_levelToExp.at(m_level + 1); }

    void OnLevelUp(exp_t exp);

    void RestoreStatus();

    void GameOver() { std::cout << m_name << "はしんでしまった！" << std::endl; }

private:
    level_t m_level;
    exp_t m_exp;
    map m_levelToExp;
    // TODO: レベルに対応するステータス表をメンバとして実装する
};

#endif // !BRAVE_H_
