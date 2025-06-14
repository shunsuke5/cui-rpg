#ifndef BRAVE_H_
#define BRAVE_H_

#include "BattleCharacter.hpp"
#include "Abnormal.hpp"

class Brave : public BattleCharacter
{

public:
    Brave() : m_state(Abnormal::NORMAL) {}
    ~Brave() {}
    Abnormal& GetState() override { return m_state; }
    void SetState(Abnormal state) override { m_state = state; }

private:
    Abnormal m_state;
};

#endif // !BRAVE_H_
