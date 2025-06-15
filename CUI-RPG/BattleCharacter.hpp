#ifndef BATTLE_CHARACTER_H_
#define BATTLE_CHARACTER_H_

#include "State.hpp"
#include <iostream>
#include <string>

class BattleCharacter
{
public:
    using string = std::string;
    using ability_t = signed short;

protected:
    struct Status
    {
        Status(ability_t hp, ability_t mp, ability_t attack, ability_t defense, ability_t speed)
            : hp(hp), mp(mp), attack(attack), defense(defense), speed(speed) {}
        ~Status() {}

        ability_t hp;
        ability_t mp;
        ability_t attack;
        ability_t defense;
        ability_t speed;
    };

public:
    BattleCharacter(string name, ability_t hp, ability_t mp, ability_t attack, ability_t defense, ability_t speed)
        : m_name(name), m_state(State::NORMAL), m_initStatus(hp, mp, attack, defense, speed), m_battleStatus(hp, mp, attack, defense, speed) {}

    virtual ~BattleCharacter() {}

    void Attack(BattleCharacter& receiver)
    {
        ability_t damage = GetBattleAttack() - (receiver.GetBattleDefense() / 2);
        receiver.SetBattleHp(receiver.GetBattleHp() - damage);
        std::cout << receiver.GetName() << " に" << damage << "ダメージ" << std::endl;
    }

    void Defense()
    {

    }

    bool IsFaster(const BattleCharacter& other) const
    {
        return GetBattleSpeed() >= other.GetBattleSpeed();
    }

    bool IsDie() { return GetBattleHp() == 0; }

    string GetName() const { return m_name; }
    State& GetState() { return m_state; }

    const ability_t GetBattleHp() const { return m_battleStatus.hp; }
    const ability_t GetBattleAttack() const { return m_battleStatus.attack; }
    const ability_t GetBattleDefense() const { return m_battleStatus.defense; }
    const ability_t GetBattleSpeed() const { return m_battleStatus.speed; }

    Status& GetInitStatus() { return m_initStatus; }
    Status& GetBattleStatus() { return m_battleStatus; }
    const Status& GetInitStatus() const { return m_initStatus; }
    const Status& GetBattleStatus() const { return m_battleStatus; }

    void SetBattleHp(ability_t hp) { m_battleStatus.hp = (hp < 0) ? 0 : hp; }
    void SetState(State state) { m_state = state; }

protected:
    string m_name;
    State m_state;
    Status m_initStatus;
    Status m_battleStatus;
};

#endif // !BATTLE_CHARACTER_H_
