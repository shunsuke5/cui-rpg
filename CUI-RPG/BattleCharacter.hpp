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

    BattleCharacter(string name, ability_t hp, ability_t mp, ability_t attack, ability_t defense, ability_t speed)
        : m_name(name), m_hp(hp), m_mp(mp), m_attack(attack), m_defense(defense), m_speed(speed), m_state(State::NORMAL) {}

    virtual ~BattleCharacter() {}

public:
    void Attack(BattleCharacter& receiver)
    {
        ability_t damage = m_attack - (receiver.GetDefense() / 2);
        receiver.SetHp(receiver.GetHp() - damage);
        std::cout << receiver.GetName() << " に" << damage << "ダメージ" << std::endl;
    }

    bool IsFaster(const BattleCharacter& another) const
    {
        return m_speed >= another.GetSpeed();
    }

    bool IsDie() { return m_hp == 0; }

    string GetName() const { return m_name; }
    ability_t GetHp() const { return m_hp; }
    ability_t GetDefense() const { return m_defense; }
    ability_t GetSpeed() const { return m_speed; }
    State& GetState() { return m_state; }

    void SetHp(ability_t hp) { m_hp = (hp < 0) ? 0 : hp; }
    void SetState(State state) { m_state = state; }

protected:
    string m_name;
    ability_t m_hp;
    ability_t m_mp;
    ability_t m_attack;
    ability_t m_defense;
    ability_t m_speed;
    State m_state;
};

#endif // !BATTLE_CHARACTER_H_
