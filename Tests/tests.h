#pragma once
#include <cassert>
#include <iostream>
#include <sstream>
#include <memory>
#include "Matrix.h"
#include "Task_1.h"
#include "Task_2.h"
#include "Task_3.h"
#include "RandomGenerate.h"
#include "ConstantGenerate.h"
#include "IStreamGenerate.h"

class Tests
{
private:
    void test_matrix_creation();
    void test_matrix_copy();
    void test_matrix_assignment();
    void test_matrix_access();
    void test_matrix_empty();
    void test_random_generator();
    void test_constant_generator();
    void test_istream_generator();
    void test_task1_swap();
    void test_task1_exceptions();
    void test_task2_remove();
    void test_task3_transform();

public:
    void run_all_tests();
};
