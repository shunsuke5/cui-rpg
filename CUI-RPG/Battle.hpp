#ifndef BATTLE_H_
#define BATTLE_H_

#include "BattleCharacter.hpp"
#include "Brave.hpp"
#include "Enemy.hpp"

class Battle
{
public:
    static void BattleEvent(Brave& brave, Enemy& enemy);

private:
    static void BattleLoop(Brave& brave, Enemy& enemy);
    static void AfterBattle(Brave& brave, Enemy& enemy);
};

#endif // !BATTLE_H_
