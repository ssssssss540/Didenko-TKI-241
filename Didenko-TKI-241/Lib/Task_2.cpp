#include "Task_2.h"

Task_2::Task_2(std::unique_ptr<Matrix> matrix, std::unique_ptr<Generator> generator, size_t start, size_t end)
{
    this->matrix_ptr = std::move(matrix);
    this->generator_ptr = std::move(generator);
    this->range_start = start;
    this->range_end = end;
}

void Task_2::Task()
{
    int removal_count = 0;

    for(size_t current = range_start; current < range_end; current++)
    {
        int current_element = (*matrix_ptr)[current - removal_count];
        if(current_element % 7 == 0)
        {
            removal_count++;
        }
    }

    remove_element(removal_count);
}

void Task_2::remove_element(size_t count_remove)
{
    std::unique_ptr<Matrix> temp_ptr = std::make_unique<Matrix>(matrix_ptr->get_length() - count_remove);
    size_t new_index = 0;
    for(size_t i = 0; i < matrix_ptr->get_length(); i++)
    {
        if((*matrix_ptr)[i] != NULL)
        {
            (*temp_ptr)[new_index] = (*matrix_ptr)[i];
            new_index++;
        }
    }

    matrix_ptr = std::move(temp_ptr);
}
