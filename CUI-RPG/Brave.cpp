#include "Brave.hpp"
#include <map>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

using level_t = unsigned short;
using exp_t = unsigned short;
using ability_t = signed short;
using string = string;

struct BraveData
{
    level_t level;
    exp_t exp;
    ability_t hp;
    ability_t mp;
    ability_t attack;
    ability_t defense;
    ability_t speed;
};

enum
{
    HP = 1,
    MP,
    ATTACK,
    DEFENSE,
    SPEED,
    EXP
};

std::streampos Brave::Init()
{
    ifstream file("leveltable.csv");
    if (!file.is_open()) {
        std::cerr << "can't open file" << std::endl;
        exit(EXIT_FAILURE);
    }

    string line;
    do {
        getline(file, line);
    } while (line.front() != '1');

    // 勇者の初期ステータスを設定する処理

    m_nextLevel = file.tellg();
}

void Brave::InitBattleStatus()
{
    m_battleStatus.hp = m_hp;
    m_battleStatus.mp = m_mp;
    m_battleStatus.attack = m_defaultStatus.attack;
    m_battleStatus.defense = m_defaultStatus.defense;
    m_battleStatus.speed = m_defaultStatus.speed;
}

void Brave::Action(BattleCharacter& enemy)
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
    }
}

bool Brave::IsLevelUp()
{
    ifstream file("leveltable.csv");
    if (!file.is_open()) {
        std::cerr << "can't open file" << std::endl;
        exit(EXIT_FAILURE);
    }

    string line;
    file.seekg(m_nextLevel);

    while (getline(file, line)) {
        std::cout << line << "   " << file.tellg() << std::endl;
    }
}

void Brave::OnLevelUp(exp_t exp)
{
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

void Brave::ReflectHpAndMp()
{
    m_hp = m_battleStatus.hp;
    m_mp = m_battleStatus.mp;
}