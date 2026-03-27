#pragma once 

class Generator
{
public:
    virtual int generate_number() = 0;
    virtual ~Generator() = default;
};
