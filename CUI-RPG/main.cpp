#include "PrintCoordinate.hpp"
#include "Brave.hpp"
#include "State.hpp"
#include "Abnormal.hpp"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    Brave brave;
    State::SetState(brave, Abnormal::POISON);
    if (State::IsState(brave, Abnormal::POISON)) { cout << "毒" << endl; }

    State::SetState(brave, Abnormal::PARALYSIS);
    if (State::IsState(brave, Abnormal::POISON) && State::IsState(brave, Abnormal::PARALYSIS)) { cout << "毒、麻痺" << endl; }

    State::RemoveState(brave, Abnormal::POISON);
    if (State::IsState(brave, Abnormal::POISON)) { cout << "麻痺" << endl; }

    State::RemoveState(brave, Abnormal::PARALYSIS);
    if (State::IsNormal(brave)) { cout << "通常" << endl; }
}