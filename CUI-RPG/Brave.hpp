#ifndef BRAVE_H_
#define BRAVE_H_

#include "BattleCharacter.hpp"
#include "Abnormal.hpp"

class Brave : public BattleCharacter
{

public:
    Brave() : m_abnormalStatus(Abnormal::NORMAL) {}
    ~Brave() {}
    Abnormal& GetState() override { return m_abnormalStatus; }

private:
    Abnormal m_abnormalStatus;
};

#endif // !BRAVE_H_
