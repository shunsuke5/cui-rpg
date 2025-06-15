#ifndef ABNORMAL_H_
#define ABNORMAL_H_

enum class State
{
    NORMAL,
    POISON,     // 00000001
    PARALYSIS,  // 00000010
    SLEEP = 4   // 00000100
};

State operator|(State target, State state);
State operator&(State target, State state);
State operator~(State state);

#endif // !ABNORMAL_H_
