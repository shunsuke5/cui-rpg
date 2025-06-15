#include "State.hpp"

State operator|(State target, State state)
{
    int result = static_cast<int>(target) | static_cast<int>(state);
    return static_cast<State>(result);
}

State operator&(State target, State state)
{
    int result = static_cast<int>(target) & static_cast<int>(state);
    return static_cast<State>(result);
}

State operator~(State state)
{
    int result = ~(static_cast<int>(state));
    return static_cast<State>(result);
}

bool operator==(State target, State state)
{
    return static_cast<int>(target) == static_cast<int>(state);
}