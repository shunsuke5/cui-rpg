#ifndef BATTLE_CHARACTER_H_
#define BATTLE_CHARACTER_H_

#include "State.hpp"
#include "StateOperation.hpp"
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
        : m_name(name), m_state(State::NORMAL), m_initStatus(hp, mp, attack, defense, speed), m_battleStatus(hp, mp, attack, defense, speed), m_isDefense(false) {
    }

    virtual ~BattleCharacter() {}

    void Attack(BattleCharacter& receiver)
    {
        ability_t damage = CalcAttackDamage(receiver);
        receiver.SetBattleHp(receiver.GetBattleHp() - damage);
        std::cout << receiver.GetName() << " に" << damage << "ダメージ" << std::endl;
    }

    int CalcAttackDamage(BattleCharacter& receiver)
    {
        ability_t damage = GetBattleAttack() - (receiver.GetBattleDefense() / 2);
        return receiver.IsDefense() ? damage / 2 : damage;
    }

    void Turn(BattleCharacter other)
    {
        UnDefense();

        if (StateOperation::IsState(*this, State::PARALYSIS)
            || StateOperation::IsState(*this, State::SLEEP)) {
            std::cout << "行動不能" << std::endl;
        } else {
            Action(other);
        }

        if (StateOperation::IsState(*this, State::POISON)) {
            PoisonDamage();
        }

        if (IsDie()) {
            // ここでどうバトルの終了を呼び出し元に通知するか？
        }
    }

    // Brave,Enemyでそれぞれ実装しなければならない
    virtual void Action(BattleCharacter other) {}

    void PoisonDamage()
    {
        m_battleStatus.hp -= 4;
        std::cout << "毒により4ダメージ" << std::endl;
    }

    void Defense() { m_isDefense = true; }

    void UnDefense() { m_isDefense = false; }

    bool IsDefense() { return m_isDefense; }

    bool IsFaster(const BattleCharacter& other) const
    {
        return GetBattleSpeed() >= other.GetBattleSpeed();
    }

    bool IsDie() { return GetBattleHp() == 0; }

    string GetName() const { return m_name; }
    State& GetState() { return m_state; }
    const State& GetState() const { return m_state; }

    const ability_t GetInitHp() const { return m_initStatus.hp; }
    const ability_t GetInitAttack() const { return m_initStatus.attack; }
    const ability_t GetInitDefense() const { return m_initStatus.defense; }
    const ability_t GetInitSpeed() const { return m_initStatus.speed; }

    const ability_t GetBattleHp() const { return m_battleStatus.hp; }
    const ability_t GetBattleAttack() const { return m_battleStatus.attack; }
    const ability_t GetBattleDefense() const { return m_battleStatus.defense; }
    const ability_t GetBattleSpeed() const { return m_battleStatus.speed; }

    Status& GetInitStatus() { return m_initStatus; }
    Status& GetBattleStatus() { return m_battleStatus; }
    const Status& GetInitStatus() const { return m_initStatus; }
    const Status& GetBattleStatus() const { return m_battleStatus; }

    void SetBattleHp(ability_t hp) { m_battleStatus.hp = (hp < 0) ? 0 : hp; }
    void SetBattleDefense(ability_t defense) { m_battleStatus.defense = defense; }
    void SetState(State state) { m_state = state; }

protected:
    string m_name;
    State m_state;
    Status m_initStatus;
    Status m_battleStatus;
    bool m_isDefense;
};

#endif // !BATTLE_CHARACTER_H_
