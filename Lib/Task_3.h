#pragma once 
#include "Exercise.h"

class Task_3: public Exercise
{
public:
    Task_3(std::unique_ptr<Matrix> matrix, std::unique_ptr<Generator> generator);
    void Task() override;
};
