#pragma once 
#include "Exercise.h"

class Task_1: public Exercise
{
private:
    int& find_last_negative() const;
    int& find_last_positive() const;
public:
    Task_1(std::unique_ptr<Matrix> matrix, std::unique_ptr<Generator> generator): Exercise(std::move(matrix), std::move(generator)){};
    void Task() override;
};
