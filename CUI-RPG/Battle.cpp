#include "Battle.hpp"

void Battle::BattleEvent(Brave& brave, Enemy& enemy)
{
    BattleLoop(brave, enemy);
    AfterBattle(brave, enemy);
}

void Battle::BattleLoop(Brave& brave, Enemy& enemy)
{
    brave.InitBattleStatus();
    enemy.InitBattleStatus();
    enemy.Encount();

    while (!brave.IsDie() && !enemy.IsDie()) {
        if (brave.IsFaster(enemy)) {
            if (!brave.Turn(enemy)) {
                break;
            }
            if (!enemy.Turn(brave)) {
                break;
            }
        } else {
            if (!enemy.Turn(brave)) {
                break;
            }
            if (!brave.Turn(enemy)) {
                break;
            }
        }
    }
}

void Battle::AfterBattle(Brave& brave, Enemy& enemy)
{
    if (brave.IsDie()) {
        brave.GameOver();
    } else if (brave.IsEscape() || enemy.IsEscape()) {
        // 何もしない
    } else {
        enemy.DiePrint();
        brave.OnLevelUp(enemy.GetExp());
        brave.ReflectHpAndMp();
    }
}