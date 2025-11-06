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
            remove_element(current - removal_count);
            removal_count++;
        }
    }

    for(size_t fill = matrix_ptr->get_length() - removal_count; fill < matrix_ptr->get_length(); fill++)
    {
        (*matrix_ptr)[fill] = 0;
    }
}

void Task_2::remove_element(size_t idx)
{
    for(size_t shift = idx; shift < matrix_ptr->get_length() - 1; shift++)
    {
        (*matrix_ptr)[shift] = (*matrix_ptr)[shift + 1];
    }
}
