#ifndef RANDOM_GENERATOR_H_
#define RANDOM_GENERATOR_H_

#include <random>

class RandomNumGenerator
{
public:
    static int Generate(int min, int max)
    {
        std::mt19937 mt{ std::random_device{}() };
        std::uniform_int_distribution<int> dist(min, max);
        return dist(mt);
    }
};

#endif // !RANDOM_GENERATOR_H_
