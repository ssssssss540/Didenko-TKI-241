#pragma once 
#include <iostream>
#include "Generator.h"

class IStreamGenerate: public Generator
{
private:
    std::istream& input_stream;
    int get_integer_input(const std::string& prompt = "");
public:
    IStreamGenerate(std::istream& stream = std::cin): input_stream(stream){};
    ~IStreamGenerate() = default;
    int generate_number() override;
};
