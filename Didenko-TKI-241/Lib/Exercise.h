#pragma once
#include <memory>
#include <string>
#include "Matrix.h"
#include "Generator.h"

class Exercise
{
protected:
    std::unique_ptr<Matrix> matrix_ptr;
    std::unique_ptr<Generator> generator_ptr;

public:
    Exercise(std::unique_ptr<Matrix> m, std::unique_ptr<Generator> g): matrix_ptr(std::move(m)), generator_ptr(std::move(g)){};
    void populate_matrix();
    virtual void Task() = 0;
    
    std::string get_matrix_string() const {
        return matrix_ptr->to_string();
    }
    
    ~Exercise() = default;
};