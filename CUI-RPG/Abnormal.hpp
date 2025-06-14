#ifndef ABNORMAL_H_
#define ABNORMAL_H_

enum class Abnormal
{
    NORMAL,
    POISON,     // 00000001
    PARALYSIS,  // 00000010
    SLEEP = 4   // 00000100
};

Abnormal operator|(Abnormal target, Abnormal state);
Abnormal operator&(Abnormal target, Abnormal state);
Abnormal operator~(Abnormal state);

#endif // !ABNORMAL_H_
