#pragma once 
#include "Exercise.h"

class Task_2: public Exercise
{
private:
    void remove_element(size_t count_remove);
    size_t range_start;
    size_t range_end;
public:
    Task_2(std::unique_ptr<Matrix> matrix, std::unique_ptr<Generator> generator, size_t start, size_t end);
    void Task() override;
};
