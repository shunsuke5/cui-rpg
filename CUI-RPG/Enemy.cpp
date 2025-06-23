#include "Enemy.hpp"

void Enemy::InitBattleStatus()
{
    m_battleStatus.hp = m_defaultStatus.hp;
    m_battleStatus.mp = m_defaultStatus.mp;
    m_battleStatus.attack = m_defaultStatus.attack;
    m_battleStatus.defense = m_defaultStatus.defense;
    m_battleStatus.speed = m_defaultStatus.speed;
}

void Enemy::Action(BattleCharacter& brave, int n)
{
    if (n == 0 || n > BASE_ACTION_COUNT) {
        n = RandomNumGenerator::FromOneToMax(BASE_ACTION_COUNT);
    }

    switch (n) {
    case 1:
        Attack(brave);
        break;
    case 2:
        Defense();
        break;
    case 3:
        Escape();
        break;
    }
}