#include "PrintCoordinate.hpp"
#include "Brave.hpp"
#include "Enemy.hpp"
#include "State.hpp"
#include "BattleCharacter.hpp"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    BattleCharacter brave("kamei", 10, 5, 5, 5, 5);
    BattleCharacter enemy("enemy", 7, 4, 3, 3, 8);

    while (!brave.IsDie() && !enemy.IsDie()) {
        if (brave.IsFaster(enemy)) {
            brave.Attack(enemy);
            enemy.Attack(brave);
        } else {
            enemy.Attack(brave);
            brave.Attack(enemy);
        }
    }
}