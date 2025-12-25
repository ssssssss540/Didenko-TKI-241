#include "Matrix.h"

Matrix::Matrix(const Matrix& other)
{
    elements = std::make_unique<int[]>(other.length);
    length = other.length;
    for(size_t j = 0; j < length; j++)
    {
        elements[j] = other[j];
    }
}

Matrix& Matrix::operator=(const Matrix& other)
{
    check_self_assignment(other);

    if(length == 0)
    {
        elements = std::make_unique<int[]>(other.length);
    }

    length = other.length;

    for(size_t k = 0; k < length; k++)
    {
        elements[k] = other[k];
    }
    
    return *this;
}

int& Matrix::operator[](size_t position)
{
    if(position >= length)
    {
        throw std::out_of_range("Position exceeds matrix length");
    }

    return elements[position];
}

const int& Matrix::operator[](size_t position) const
{
    if(position >= length)
    {
        throw std::out_of_range("Position exceeds matrix length");
    }

    return elements[position];
}

size_t Matrix::get_length()
{
    return length;
}

const std::string Matrix::to_string() const
{
    check_empty();

    std::string result = "( ";
    
    for(size_t m = 0; m < length; m++)
    {
        result += std::to_string(elements[m]);
        if(m != length - 1)
        {
            result += ", ";
        }
    }
    
    result += " )";
    return result;
}

void Matrix::check_empty() const
{
    if(length == 0)
    {
        throw std::logic_error("Matrix is empty");
    }
}

void Matrix::check_self_assignment(const Matrix& other) const
{
    if(this == &other)
    {
        throw std::logic_error("Self assignment detected");
    }
}
