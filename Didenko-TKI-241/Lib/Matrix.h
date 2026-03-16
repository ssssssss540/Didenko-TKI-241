#pragma once 
#include <memory>
#include <stdexcept>
#include <string>
#include "Generator.h"

class Matrix
{
private:
    std::unique_ptr<int[]> elements = nullptr;
    size_t length;
    void check_empty() const;
    void check_self_assignment(const Matrix& other) const;
public:
    Matrix(): length(0){};
    Matrix(const size_t length): length(length), elements(std::make_unique<int[]>(length)){};
    Matrix(const Matrix& other);
    Matrix(Matrix&& other) noexcept = default;
    Matrix& operator=(const Matrix& other);
    Matrix& operator=(Matrix&& other) noexcept = default;
    ~Matrix() = default;
    int& operator[](size_t position);
    const int& operator[](size_t position) const;
    size_t get_length();
    const std::string to_string() const;
};
