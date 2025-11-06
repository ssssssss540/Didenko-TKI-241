#pragma once 
#include "Generator.h"

class ConstantGenerate: public Generator
{
private:
    int fixed_value;

public:
    int generate_number() override;
    ~ConstantGenerate() = default;
    ConstantGenerate(const int value): fixed_value(value){};
};
