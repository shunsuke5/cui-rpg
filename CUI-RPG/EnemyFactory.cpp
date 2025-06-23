#include "EnemyFactory.hpp"

// CSVファイル内での各データの列位置(先頭の"名前"を0とする)
enum
{
    HP = 1,
    MP,
    ATTACK,
    DEFENSE,
    SPEED,
    EXP
};

EnemyFactory::EnemyData EnemyFactory::GetEnemyData(string name)
{
    std::ifstream file("enemy.csv");
    if (!file.is_open()) {
        std::cerr << "can't open file" << std::endl;
        std::exit(EXIT_FAILURE);
    }

    string line;
    string getName;

    while (getline(file, line)) {
        getName = line.substr(0, line.find(','));
        if (name.length() != getName.length() || name != getName) {
            continue;
        } else {
            break;
        }

    }

    EnemyData enemyData;
    int column = HP;

    while (column <= EXP) {
        line = line.substr(line.find(',') + 1);
        int status = std::stoi(line.substr(0, line.find(',')));

        switch (column) {
        case HP:
            enemyData.hp = status;
            break;
        case MP:
            enemyData.mp = status;
            break;
        case ATTACK:
            enemyData.attack = status;
            break;
        case DEFENSE:
            enemyData.defense = status;
            break;
        case SPEED:
            enemyData.speed = status;
            break;
        case EXP:
            enemyData.exp = status;
            break;
        }

        ++column;
    }

    file.close();
    return enemyData;
}