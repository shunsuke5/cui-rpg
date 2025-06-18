#ifndef BATTLE_H_
#define BATTLE_H_

#include "BattleCharacter.hpp"
#include "Brave.hpp"

class Battle
{
public:
    static void BattleEvent(Brave* brave, Enemy* enemy)
    {
        BattleLoop(brave, enemy);
        AfterBattle(brave, enemy);
    }

    static void BattleLoop(Brave* brave, Enemy* enemy)
    {
        enemy->Encount();

        while (!brave->IsDie() && !enemy->IsDie()) {
            if (brave->IsFaster(enemy)) {
                if (!brave->Turn(enemy)) {
                    break;
                }
                if (!enemy->Turn(brave)) {
                    break;
                }
            } else {
                if (!enemy->Turn(brave)) {
                    break;
                }
                if (!brave->Turn(enemy)) {
                    break;
                }
            }
        }
    }

    static void AfterBattle(Brave* brave, Enemy* enemy)
    {
        if (brave->IsDie()) {
            brave->GameOver();
        } else {
            enemy->DiePrint();
            brave->OnLevelUp(enemy->GetExp());
        }
    }
};

#endif // !BATTLE_H_
