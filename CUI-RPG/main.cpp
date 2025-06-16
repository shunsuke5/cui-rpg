#include "PrintCoordinate.hpp"
#include "Brave.hpp"
#include "Enemy.hpp"
#include "State.hpp"
#include "StateOperation.hpp"
#include "BattleCharacter.hpp"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    BattleCharacter brave("kamei", 10, 5, 5, 5, 5);
    BattleCharacter enemy("enemy", 7, 4, 3, 3, 8);
    StateOperation::SetState(brave, State::POISON);

    while (!brave.IsDie() && !enemy.IsDie()) {
        if (brave.IsFaster(enemy)) {
            brave.Turn(enemy);
            enemy.Turn(brave);
        } else {
            enemy.Turn(brave);
            brave.Turn(enemy);
        }
    }
}