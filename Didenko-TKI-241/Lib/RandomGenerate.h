#pragma once
#include <stdexcept>
#include <random>
#include "Generator.h"

class RandomGenerate: public Generator
{
private:
    int lower_bound, upper_bound;
    std::mt19937 random_engine;
    std::uniform_int_distribution<int> distribution;
public:
    ~RandomGenerate() = default;
    int generate_number() override;
    RandomGenerate(const int lower, const int upper);
};
