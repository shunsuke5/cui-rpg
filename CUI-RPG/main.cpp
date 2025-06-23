#include "PrintCoordinate.hpp"
#include "Brave.hpp"
#include "Enemy.hpp"
#include "State.hpp"
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

    ifstream file("leveltable.csv");
    if (!file.is_open()) {
        cerr << "can't open file" << endl;
        exit(EXIT_FAILURE);
    }

    string line;
    file.seekg(77);

    while (getline(file, line)) {
        cout << line << "   " << file.tellg() << endl;
    }
}