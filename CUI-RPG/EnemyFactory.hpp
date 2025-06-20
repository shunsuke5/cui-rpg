#ifndef ENEMY_FACTORY_H_
#define ENEMY_FACTORY_H_

#include "BigBear.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

class EnemyFactory
{
public:
    using string = std::string;
    using ability_t = signed short;
    using exp_t = unsigned short;

    struct EnemyData
    {
        ability_t hp;
        ability_t mp;
        ability_t attack;
        ability_t defense;
        ability_t speed;
        exp_t exp;
    };

    static EnemyData GetData(string name)
    {
        std::ifstream file("test.csv");
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
        std::cout << line << std::endl;

        // どうにか上手いことループで回していきたい
        EnemyData enemyData;
        line = line.substr(line.find(',') + 1);
        enemyData.hp = std::stoi(line.substr(0, line.find(',')));

        line = line.substr(line.find(',') + 1);
        enemyData.mp = std::stoi(line.substr(0, line.find(',')));

        line = line.substr(line.find(',') + 1);
        enemyData.attack = std::stoi(line.substr(0, line.find(',')));

        line = line.substr(line.find(',') + 1);
        enemyData.defense = std::stoi(line.substr(0, line.find(',')));

        line = line.substr(line.find(',') + 1);
        enemyData.speed = std::stoi(line.substr(0, line.find(',')));

        line = line.substr(line.find(',') + 1);
        enemyData.exp = std::stoi(line.substr(0, line.find(',')));

        //string lastParam = line.substr(line.rfind(','));
        //string a = line.substr(0, line.find(','));
        //while (a != lastParam) {

        //}

        file.close();
        return enemyData;
    }

    // TODO: 戻り値を参照やらポインタにした方が
    // コピーが発生しなくて効率が良さそうなので
    // もし変えられそうなら変える
    static BigBear GenerateBigBear(Brave& brave)
    {
        string name = "おおぐま";
        EnemyData bigBear = GetData(name);
        return BigBear(brave, name,
            bigBear.hp, bigBear.mp, bigBear.attack,
            bigBear.defense, bigBear.speed, bigBear.exp);
    }
};

#endif // !ENEMY_FACTORY_H_
