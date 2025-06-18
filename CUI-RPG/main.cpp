#include "PrintCoordinate.hpp"
#include "Brave.hpp"
#include "Enemy.hpp"
#include "State.hpp"
#include "StateOperation.hpp"
#include "BattleCharacter.hpp"
#include "BigBear.hpp"
#include "Battle.hpp"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    Brave* brave = new Brave("しゅんすけ", 10, 5, 5, 5, 5);
    Enemy* enemy = new BigBear();

    Battle::BattleEvent(brave, enemy);
}