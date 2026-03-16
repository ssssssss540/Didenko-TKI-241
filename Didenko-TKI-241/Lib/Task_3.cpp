#include "Task_3.h"

Task_3::Task_3(std::unique_ptr<Matrix> matrix, std::unique_ptr<Generator> generator)
{
    this->matrix_ptr = std::move(matrix);
    this->generator_ptr = std::move(generator);
}

void Task_3::Task()
{
    for(size_t idx = 0; idx < matrix_ptr->get_length(); idx++)
    {
        if(idx % 2 == 0)
        {
            (*matrix_ptr)[idx] = (*matrix_ptr)[idx] * (*matrix_ptr)[idx] + idx;
        }
        else {
            (*matrix_ptr)[idx] = (*matrix_ptr)[idx] * idx;
        }
    }
}
