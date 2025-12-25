#include "Task_1.h"

void Task_1::Task()
{
    try{
        int& negative = find_last_negative();
        int& positive = find_last_positive();
        
        int temporary = negative;
        negative = positive;
        positive = temporary;
    }
    catch(const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << '\n';
    }
}

int& Task_1::find_last_negative() const
{
    for(size_t i = matrix_ptr->get_length() - 1; i >= 0; i--)
    {
        if((*matrix_ptr)[i] < 0)
        {
            return (*matrix_ptr)[i];
        }
    }
    throw std::runtime_error("No negative elements found");
}

int& Task_1::find_last_positive() const
{
    for(size_t i = matrix_ptr->get_length() - 1; i >= 0; i--)
    {
        if((*matrix_ptr)[i] > 0)
        {
            return (*matrix_ptr)[i];
        }
    }
    throw std::runtime_error("No positive elements found");
}
