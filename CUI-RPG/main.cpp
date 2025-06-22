#include "PrintCoordinate.hpp"
#include "Brave.hpp"
#include "Enemy.hpp"
#include "State.hpp"
#include "StateOperation.hpp"
#include "BattleCharacter.hpp"
#include "BigBear.hpp"
#include "Battle.hpp"
#include "EnemyFactory.hpp"
#include "ForestEnemyFactory.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    Brave brave = Brave("しゅんすけ", 10, 5, 5, 5, 5);

    BigBear bear = ForestEnemyFactory::GenerateBigBear(brave);
    Battle::BattleEvent(brave, bear);

    PoisonSnake snake = ForestEnemyFactory::GeneratePoisonSnake(brave);
    Battle::BattleEvent(brave, snake);
    cout << (int)brave.GetState() << endl;

    // 必要経験値をざっくり計算したやつ(後々調整する)
    int exp = 3;
    for (int i = 2; i < 21; ++i) {
        cout << "レベル：" << i << ", 経験値：" << exp << endl;
        exp *= 1.75;
    }
}