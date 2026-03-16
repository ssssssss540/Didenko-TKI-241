#include "tests.h"

TEST_F(Tests, MatrixCreation) {
    Matrix m1(5);
    EXPECT_EQ(m1.get_length(), 5);
    
    Matrix m2(0);
    EXPECT_EQ(m2.get_length(), 0);
}

TEST_F(Tests, MatrixCopy) {
    Matrix original(3);
    original[0] = 1;
    original[1] = 2;
    original[2] = 3;
    
    Matrix copy(original);
    EXPECT_EQ(copy.get_length(), 3);
    EXPECT_EQ(copy[0], 1);
    EXPECT_EQ(copy[1], 2);
    EXPECT_EQ(copy[2], 3);
}

TEST_F(Tests, MatrixAssignment) {
    Matrix m1(3);
    m1[0] = 10;
    m1[1] = 20;
    m1[2] = 30;
    
    Matrix m2(2);
    m2 = m1;
    
    EXPECT_EQ(m2.get_length(), 3);
    EXPECT_EQ(m2[0], 10);
    EXPECT_EQ(m2[1], 20);
    EXPECT_EQ(m2[2], 30);
}

TEST_F(Tests, MatrixAccess) {
    Matrix m(3);
    m[0] = 100;
    m[1] = 200;
    m[2] = 300;
    
    EXPECT_EQ(m[0], 100);
    EXPECT_EQ(m[1], 200);
    EXPECT_EQ(m[2], 300);
    
    EXPECT_THROW(m[5], std::exception);
}

TEST_F(Tests, MatrixEmpty) {
    Matrix m(0);
    EXPECT_THROW(m.to_string(), std::exception);
}

TEST_F(Tests, RandomGenerator) {
    RandomGenerate gen(-10, 10);
    
    for (int i = 0; i < 100; i++) {
        int value = gen.generate_number();
        EXPECT_GE(value, -10);
        EXPECT_LE(value, 10);
    }
    
    EXPECT_THROW(RandomGenerate invalid(10, 5), std::exception);
}

TEST_F(Tests, ConstantGenerator) {
    ConstantGenerate gen(42);
    
    for (int i = 0; i < 10; i++) {
        EXPECT_EQ(gen.generate_number(), 42);
    }
}

TEST_F(Tests, IStreamGenerator) {
    std::stringstream ss;
    ss << "123\n";
    
    IStreamGenerate gen(ss);
    EXPECT_EQ(gen.generate_number(), 123);
    
    std::stringstream ss2;
    ss2 << "abc\n";
    
    IStreamGenerate gen2(ss2);
    EXPECT_THROW(gen2.generate_number(), std::exception);
}

TEST_F(Tests, Task1_Swap) {
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
    
    EXPECT_EQ((*task.matrix_ptr)[3], 2);
    EXPECT_EQ((*task.matrix_ptr)[4], -7);
}

TEST_F(Tests, Task1_Exceptions) {
    auto matrix = std::make_unique<Matrix>(3);
    auto generator = std::make_unique<ConstantGenerate>(1);
    
    Task_1 task(std::move(matrix), std::move(generator));
    task.populate_matrix();
    
    (*task.matrix_ptr)[0] = 1;
    (*task.matrix_ptr)[1] = 2;
    (*task.matrix_ptr)[2] = 3;
    
    
    EXPECT_NO_THROW(task.Task());
}

TEST_F(Tests, Task2_Remove) {
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
    
    EXPECT_EQ((*task.matrix_ptr)[0], 3);
    EXPECT_EQ((*task.matrix_ptr)[1], 5);
    EXPECT_EQ((*task.matrix_ptr)[4], 0);
    EXPECT_EQ((*task.matrix_ptr)[5], 0);
}

TEST_F(Tests, Task3_Transform) {
    auto matrix = std::make_unique<Matrix>(4);
    auto generator = std::make_unique<ConstantGenerate>(2);
    
    Task_3 task(std::move(matrix), std::move(generator));
    task.populate_matrix();
    
    (*task.matrix_ptr)[0] = 3;
    (*task.matrix_ptr)[1] = 4;
    (*task.matrix_ptr)[2] = 5;
    (*task.matrix_ptr)[3] = 6;
    
    task.Task();
    
    EXPECT_EQ((*task.matrix_ptr)[0], 3*3 + 0);
    EXPECT_EQ((*task.matrix_ptr)[1], 4*1);
    EXPECT_EQ((*task.matrix_ptr)[2], 5*5 + 2);
    EXPECT_EQ((*task.matrix_ptr)[3], 6*3);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
