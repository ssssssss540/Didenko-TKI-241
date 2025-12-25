#pragma once
#include <iostream>
#include <memory>
#include <limits>
#include <string>
#include "Generator.h"
#include "RandomGenerate.h"
#include "ConstantGenerate.h"
#include "IStreamGenerate.h"

class InputHandler {
public:
    
    static int get_integer_input(const std::string& prompt);
    
   
    static int get_positive_integer(const std::string& prompt);
    
    
    static std::unique_ptr<Generator> choose_generator();
    
    
    static size_t get_matrix_size();
};