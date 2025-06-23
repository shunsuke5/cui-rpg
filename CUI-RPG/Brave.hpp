#ifndef BRAVE_H_
#define BRAVE_H_

#include "BattleCharacter.hpp"
#include <iostream>
#include <fstream>
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

        //m_levelToExp = GenerateLevelToExp();
    }
    ~Brave() {}

    //static map GenerateLevelToExp();

    std::streampos Init();

    void InitBattleStatus();

    void Action(BattleCharacter& enemy);

    bool IsLevelUp();

    void OnLevelUp(exp_t exp);

    void ReflectHpAndMp();

    void GameOver() { std::cout << m_name << "はしんでしまった！" << std::endl; }

    ability_t GetHp() { return m_hp; }
    ability_t GetMp() { return m_mp; }
    void SetHp(ability_t hp) { m_hp = (hp < 0) ? 0 : hp; }
    void SetMp(ability_t mp) { m_mp = (mp < 0) ? 0 : mp; }

private:
    level_t m_level;
    exp_t m_exp;
    ability_t m_hp;
    ability_t m_mp;
    //map m_levelToExp;
    std::streampos m_nextLevel;
};

#endif // !BRAVE_H_
