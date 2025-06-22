#include "Brave.hpp"
#include <map>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

using level_t = unsigned short;
using exp_t = unsigned short;
using string = string;

map<level_t, exp_t> Brave::GenerateLevelToExp()
{
    ifstream file("leveltable.csv");
    if (!file.is_open()) {
        cerr << "can't open file" << endl;
        exit(EXIT_FAILURE);
    }

    map levelToExp;
    string line;
    level_t level;
    exp_t exp;
    getline(file, line);

    while (getline(file, line)) {
        level = stoi(line.substr(0, line.find(',')));
        exp = stoi(line.substr(line.find(',') + 1));

        levelToExp.insert(std::make_pair(level, exp));
    }

    return levelToExp;
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

void Brave::RestoreStatus()
{
    m_battleStatus.attack = m_initStatus.attack;
    m_battleStatus.defense = m_initStatus.defense;
    m_battleStatus.speed = m_initStatus.speed;
}