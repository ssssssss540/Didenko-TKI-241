#pragma once
#include <memory>

class Generator {
public:
  
    Generator() = default;
    
    virtual int generate_number() = 0;
    
    virtual ~Generator() = default;
};
