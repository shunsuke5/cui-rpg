#include "PrintCoordinate.hpp"
#include "Brave.hpp"
#include "Enemy.hpp"
#include "State.hpp"
#include "StateOperation.hpp"
#include "BattleCharacter.hpp"
#include "BigBear.hpp"
#include "Battle.hpp"
#include <iostream>
#include <vector>
using namespace std;

class A {};

class B : public A
{
public:
    B(A& a) : m_pA(a) {}
    ~B() {}
    A& m_pA;
};

int main()
{
    Brave brave = Brave("しゅんすけ", 10, 5, 5, 5, 5);
    Enemy enemy = BigBear();

    Battle::BattleEvent(brave, enemy);

    A a;
    {
        B b(a);
        cout << &b.m_pA << endl;
    }

    cout << &a << endl;
}