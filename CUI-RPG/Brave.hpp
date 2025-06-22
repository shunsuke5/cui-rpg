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

        // 想定通りファイルから値が格納されているかの確認
        for (auto i = m_levelToExp.begin(); i != m_levelToExp.end(); ++i) {
            std::cout << i->first << " " << i->second << std::endl;
        }
    }
    ~Brave() {}

    static map GenerateLevelToExp();

    void Action(BattleCharacter& enemy)
    {
        int n = 0;

        std::cout << "1：こうげき　2：ぼうぎょ　3：にげる" << std::endl;
        std::cout << m_name << "はどうする？ > " << std::flush;

        while (!(std::cin >> n) || n < 1 || n > 3) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << m_name << "はどうする？ > " << std::flush;
        }

        switch (n) {
        case 1:
            Attack(enemy);
            break;
        case 2:
            Defense();
            break;
        case 3:
            Escape();
            break;
        default:
            break;
        }
    }

    bool IsLevelUp() { return m_exp >= m_levelToExp.at(m_level + 1); }

    void OnLevelUp(exp_t exp)
    {
        // 最大レベルは20とする
        const level_t MAX_LEVEL = 20;

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
    level_t m_level;
    exp_t m_exp;
    map m_levelToExp;
    // TODO: レベルに対応するステータス表をメンバとして実装する
};

#endif // !BRAVE_H_
