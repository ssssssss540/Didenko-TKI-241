#include "tests.h"

void Tests::test_matrix_creation()
{
    Matrix m1(5);
    assert(m1.get_length() == 5);
    
    Matrix m2(0);
    assert(m2.get_length() == 0);
    
    std::cout << "test_matrix_creation: PASSED\n";
}

void Tests::test_matrix_copy()
{
    Matrix original(3);
    original[0] = 1;
    original[1] = 2;
    original[2] = 3;
    
    Matrix copy(original);
    assert(copy.get_length() == 3);
    assert(copy[0] == 1);
    assert(copy[1] == 2);
    assert(copy[2] == 3);
    
    std::cout << "test_matrix_copy: PASSED\n";
}

void Tests::test_matrix_assignment()
{
    Matrix m1(3);
    m1[0] = 10;
    m1[1] = 20;
    m1[2] = 30;
    
    Matrix m2(2);
    m2 = m1;
    
    assert(m2.get_length() == 3);
    assert(m2[0] == 10);
    assert(m2[1] == 20);
    assert(m2[2] == 30);
    
    std::cout << "test_matrix_assignment: PASSED\n";
}

void Tests::test_matrix_access()
{
    Matrix m(3);
    m[0] = 100;
    m[1] = 200;
    m[2] = 300;
    
    assert(m[0] == 100);
    assert(m[1] == 200);
    assert(m[2] == 300);
    
    try {
        m[5];
        assert(false);
    } catch (const std::exception&) {
    }
    
    std::cout << "test_matrix_access: PASSED\n";
}

void Tests::test_matrix_empty()
{
    Matrix m(0);
    try {
        m.to_string();
        assert(false);
    } catch (const std::exception&) {
    }
    
    std::cout << "test_matrix_empty: PASSED\n";
}

void Tests::test_random_generator()
{
    RandomGenerate gen(-10, 10);
    
    for (int i = 0; i < 100; i++) {
        int value = gen.generate_number();
        assert(value >= -10 && value <= 10);
    }
    
    try {
        RandomGenerate invalid(10, 5);
        assert(false);
    } catch (const std::exception&) {
    }
    
    std::cout << "test_random_generator: PASSED\n";
}

void Tests::test_constant_generator()
{
    ConstantGenerate gen(42);
    
    for (int i = 0; i < 10; i++) {
        assert(gen.generate_number() == 42);
    }
    
    std::cout << "test_constant_generator: PASSED\n";
}

void Tests::test_istream_generator()
{
    std::stringstream ss;
    ss << "123\n";
    
    IStreamGenerate gen(ss);
    assert(gen.generate_number() == 123);
    
    std::stringstream ss2;
    ss2 << "abc\n";
    
    IStreamGenerate gen2(ss2);
    try {
        gen2.generate_number();
        assert(false);
    } catch (const std::exception&) {
    }
    
    std::cout << "test_istream_generator: PASSED\n";
}

void Tests::test_task1_swap()
{
    auto matrix = std::make_unique<Matrix>(5);
    auto generator = std::make_unique<ConstantGenerate>(-1);
    
    Task_1 task(std::move(matrix), std::move(generator));
    task.populate_matrix();
    
    (*task.matrix_ptr)[0] = 5;
    (*task.matrix_ptr)[1] = -3;
    (*task.matrix_ptr)[2] = 8;
    (*task.matrix_ptr)[3] = -7;
    (*task.matrix_ptr)[4] = 2;
    
    task.Task();
    
    assert((*task.matrix_ptr)[3] == 2);
    assert((*task.matrix_ptr)[4] == -7);
    
    std::cout << "test_task1_swap: PASSED\n";
}

void Tests::test_task1_exceptions()
{
    auto matrix = std::make_unique<Matrix>(3);
    auto generator = std::make_unique<ConstantGenerate>(1);
    
    Task_1 task(std::move(matrix), std::move(generator));
    task.populate_matrix();
    
    (*task.matrix_ptr)[0] = 1;
    (*task.matrix_ptr)[1] = 2;
    (*task.matrix_ptr)[2] = 3;
    
    task.Task();
    
    std::cout << "test_task1_exceptions: PASSED\n";
}

void Tests::test_task2_remove()
{
    auto matrix = std::make_unique<Matrix>(6);
    auto generator = std::make_unique<ConstantGenerate>(7);
    
    Task_2 task(std::move(matrix), std::move(generator), 0, 6);
    task.populate_matrix();
    
    (*task.matrix_ptr)[0] = 7;
    (*task.matrix_ptr)[1] = 14;
    (*task.matrix_ptr)[2] = 3;
    (*task.matrix_ptr)[3] = 21;
    (*task.matrix_ptr)[4] = 5;
    (*task.matrix_ptr)[5] = 28;
    
    task.Task();
    
    assert((*task.matrix_ptr)[0] == 3);
    assert((*task.matrix_ptr)[1] == 5);
    assert((*task.matrix_ptr)[4] == 0);
    assert((*task.matrix_ptr)[5] == 0);
    
    std::cout << "test_task2_remove: PASSED\n";
}

void Tests::test_task3_transform()
{
    auto matrix = std::make_unique<Matrix>(4);
    auto generator = std::make_unique<ConstantGenerate>(2);
    
    Task_3 task(std::move(matrix), std::move(generator));
    task.populate_matrix();
    
    (*task.matrix_ptr)[0] = 3;
    (*task.matrix_ptr)[1] = 4;
    (*task.matrix_ptr)[2] = 5;
    (*task.matrix_ptr)[3] = 6;
    
    task.Task();
    
    assert((*task.matrix_ptr)[0] == 3*3 + 0);
    assert((*task.matrix_ptr)[1] == 4*1);
    assert((*task.matrix_ptr)[2] == 5*5 + 2);
    assert((*task.matrix_ptr)[3] == 6*3);
    
    std::cout << "test_task3_transform: PASSED\n";
}

void Tests::run_all_tests()
{
    std::cout << "Running tests...\n\n";
    
    test_matrix_creation();
    test_matrix_copy();
    test_matrix_assignment();
    test_matrix_access();
    test_matrix_empty();
    test_random_generator();
    test_constant_generator();
    test_istream_generator();
    test_task1_swap();
    test_task1_exceptions();
    test_task2_remove();
    test_task3_transform();
    
    std::cout << "\nAll tests PASSED!\n";
}
