#include "PrintCoordinate.hpp"
#include "Brave.hpp"
#include "Enemy.hpp"
#include "State.hpp"
#include "StateOperation.hpp"
#include "BattleCharacter.hpp"
#include "BigBear.hpp"
#include "Battle.hpp"
#include "EnemyFactory.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    Brave brave = Brave("しゅんすけ", 10, 5, 5, 5, 5);
    BigBear enemy = EnemyFactory::GenerateBigBear(brave);

    Battle::BattleEvent(brave, enemy);

    // substr(num)は、先頭からnum文字目を切り取る
    // いや、a.substr(3) とすると、おぐま,5,0 となったので、
    // 正確にはnumバイト目か？
    string a = "おおぐま,5,0";
    a = a.substr(a.find(',') + 1);
    cout << a << endl;    // 5,0
}