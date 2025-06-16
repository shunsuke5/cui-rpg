#ifndef ABNORMAL_H_
#define ABNORMAL_H_

enum class State
{
    NORMAL,
    POISON = 1 << 0,
    PARALYSIS = 1 << 1,
    SLEEP = 1 << 2
};

State operator|(State target, State state);
State operator&(State target, State state);
State operator~(State state);

#endif // !ABNORMAL_H_
