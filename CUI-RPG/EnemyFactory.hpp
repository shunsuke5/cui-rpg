#ifndef ENEMY_FACTORY_H_
#define ENEMY_FACTORY_H_

#include "Brave.hpp"
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

    static EnemyData GetEnemyData(string name);
};

#endif // !ENEMY_FACTORY_H_
