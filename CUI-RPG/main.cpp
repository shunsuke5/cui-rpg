#include "PrintCoordinate.hpp"
#include "Brave.hpp"
#include "Enemy.hpp"
#include "State.hpp"
#include "StateOperation.hpp"
#include "BattleCharacter.hpp"
#include <iostream>
#include <vector>
using namespace std;

class A
{
public:
    virtual void a() { cout << "A" << endl; }
};

class B : public A
{
    void a() { cout << "B" << endl; }
};

int main()
{
    A* b = new B();
    b->a();

    A* a = new A();
    a->a();

    BattleCharacter* brave = new Brave("kamei", 10, 5, 5, 5, 5);
    BattleCharacter* enemy = new Enemy("enemy", 7, 4, 3, 3, 8);
    StateOperation::SetState(brave, State::POISON);

    while (!brave->IsDie() && !enemy->IsDie()) {
        if (brave->IsFaster(enemy)) {
            if (!brave->Turn(enemy)) {
                break;
            }
            if (!enemy->Turn(brave)) {
                break;
            }
        } else {
            if (!enemy->Turn(brave)) {
                break;
            }
            if (!brave->Turn(enemy)) {
                break;
            }
        }
    }
}