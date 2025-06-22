#ifndef FOREST_ENEMY_FACTORY_H_
#define FOREST_ENEMY_FACTORY_H_

#include "EnemyFactory.hpp"
#include "BigBear.hpp"
#include "PoisonSnake.hpp"
#include <string>

class ForestEnemyFactory : public EnemyFactory
{
public:
    static BigBear GenerateBigBear(Brave& brave)
    {
        string name = "おおぐま";
        EnemyData bigBear = GetEnemyData(name);

        return BigBear(brave, name,
            bigBear.hp, bigBear.mp, bigBear.attack,
            bigBear.defense, bigBear.speed, bigBear.exp);
    }

    static PoisonSnake GeneratePoisonSnake(Brave& brave)
    {
        string name = "どくへび";
        EnemyData poisonSnake = GetEnemyData(name);

        return PoisonSnake(brave, name,
            poisonSnake.hp, poisonSnake.mp, poisonSnake.attack,
            poisonSnake.defense, poisonSnake.speed, poisonSnake.exp);
    }
};

#endif // !FOREST_ENEMY_FACTORY_H_
