#include "RandomGenerate.h"

RandomGenerate::RandomGenerate(const int lower, const int upper)
{
    if(lower >= upper)
    {
        throw std::invalid_argument("Lower bound must be less than upper bound");
    }

    this->random_engine = std::mt19937(std::random_device{}());
    this->lower_bound = lower;
    this->upper_bound = upper;
    this->distribution = std::uniform_int_distribution<int>(lower, upper);
}

int RandomGenerate::generate_number()
{
    int random_value = distribution(random_engine);
    return random_value;
}
