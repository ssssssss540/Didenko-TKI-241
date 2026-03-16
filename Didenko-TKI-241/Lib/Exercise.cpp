#include "Exercise.h"

void Exercise::populate_matrix()
{
    for(size_t p = 0; p < matrix_ptr->get_length(); p++)
    {
        (*matrix_ptr)[p] = generator_ptr->generate_number();  
    }
}

