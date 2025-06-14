#include "Abnormal.hpp"

Abnormal operator|(Abnormal target, Abnormal state)
{
    int result = static_cast<int>(target) | static_cast<int>(state);
    return static_cast<Abnormal>(result);
}

Abnormal operator&(Abnormal target, Abnormal state)
{
    int result = static_cast<int>(target) & static_cast<int>(state);
    return static_cast<Abnormal>(result);
}

Abnormal operator~(Abnormal state)
{
    int result = ~(static_cast<int>(state));
    return static_cast<Abnormal>(result);
}

bool operator==(Abnormal target, Abnormal state)
{
    return static_cast<int>(target) == static_cast<int>(state);
}