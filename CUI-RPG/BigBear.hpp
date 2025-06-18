#ifndef BIG_BEAR_H_
#define BIG_BEAR_H_

#include "Enemy.hpp"

class BigBear : public Enemy
{
public:
    BigBear() : Enemy("おおぐま", 5, 0, 3, 3, 3, 10) {}
};

#endif // !BIG_BEAR_H_
