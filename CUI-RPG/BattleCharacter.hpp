#ifndef BATTLE_CHARACTER_H_
#define BATTLE_CHARACTER_H_

#include "State.hpp"
#include <iostream>
#include <string>

class StateOperation;

class BattleCharacter
{
public:
    using string = std::string;
    using ability_t = signed short;

protected:
    struct Status
    {
        Status(ability_t hp, ability_t mp, ability_t attack, ability_t defense, ability_t speed)
            : hp(hp), mp(mp), attack(attack), defense(defense), speed(speed) {
        }
        ~Status() {}

        ability_t hp;
        ability_t mp;
        ability_t attack;
        ability_t defense;
        ability_t speed;
    };

public:
    BattleCharacter(string name, ability_t hp, ability_t mp, ability_t attack, ability_t defense, ability_t speed)
        : m_name(name), m_state(State::NORMAL), m_initStatus(hp, mp, attack, defense, speed), m_battleStatus(hp, mp, attack, defense, speed), m_isDefense(false), m_isEscape(false) {
    }

    virtual ~BattleCharacter() {}

    void Attack(BattleCharacter& receiver)
    {
        std::cout << m_name << "のこうげき！" << std::endl;
        ability_t damage = CalcAttackDamage(receiver);
        receiver.SetBattleHp(receiver.GetBattleHp() - damage);
        std::cout << receiver.GetName() << "に " << damage << " ダメージ" << std::endl;
    }

    int CalcAttackDamage(BattleCharacter& receiver)
    {
        ability_t damage = GetBattleAttack() - (receiver.GetBattleDefense() / 2);
        return receiver.IsDefense() ? damage / 2 : damage;
    }

    bool Turn(BattleCharacter& other);

    virtual void Action(BattleCharacter& other) = 0;

    void PoisonDamage()
    {
        int damage = 2;
        std::cout << m_name << "はどくで " << damage << " ダメージをうけた！" << std::endl;
        SetBattleHp(GetBattleHp() - damage);
    }

    void Defense()
    {
        std::cout << m_name << "はぼうぎょのかまえをとっている。" << std::endl;
        m_isDefense = true;
    }

    bool IsDefense() const { return m_isDefense; }

    void Escape()
    {
        std::cout << m_name << "はにげだした！" << std::endl;
        m_isEscape = true;
    }

    bool IsEscape() const { return m_isEscape; }

    void InitIsEscape() { m_isEscape = false; }

    bool IsFaster(const BattleCharacter& other) const
    {
        return GetBattleSpeed() >= other.GetBattleSpeed();
    }

    bool IsDie() { return GetBattleHp() == 0; }

    string GetName() const { return m_name; }
    State& GetState() { return m_state; }
    const State& GetState() const { return m_state; }

    ability_t GetInitHp() const { return m_initStatus.hp; }
    ability_t GetInitAttack() const { return m_initStatus.attack; }
    ability_t GetInitDefense() const { return m_initStatus.defense; }
    ability_t GetInitSpeed() const { return m_initStatus.speed; }

    ability_t GetBattleHp() const { return m_battleStatus.hp; }
    ability_t GetBattleAttack() const { return m_battleStatus.attack; }
    ability_t GetBattleDefense() const { return m_battleStatus.defense; }
    ability_t GetBattleSpeed() const { return m_battleStatus.speed; }

    Status& GetInitStatus() { return m_initStatus; }
    Status& GetBattleStatus() { return m_battleStatus; }
    const Status& GetInitStatus() const { return m_initStatus; }
    const Status& GetBattleStatus() const { return m_battleStatus; }

    void SetBattleHp(ability_t hp) { m_battleStatus.hp = (hp < 0) ? 0 : hp; }
    void SetBattleDefense(ability_t defense) { m_battleStatus.defense = defense; }

    void SetState(State abnormal) { m_state = (m_state | abnormal); }
    void RemoveState(State abnormal) { m_state = (m_state & ~abnormal); }
    bool IsState(State abnormal) const { return (m_state & abnormal) == abnormal; }

private:
    void UnDefense() { m_isDefense = false; }

protected:
    string m_name;
    State m_state;
    Status m_initStatus;
    Status m_battleStatus;
    bool m_isDefense;
    bool m_isEscape;
};

#endif // !BATTLE_CHARACTER_H_
