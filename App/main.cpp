#include <iostream>
#include <memory>
#include "Task_1.h"
#include "Task_2.h"
#include "Task_3.h"
#include "RandomGenerate.h"
#include "ConstantGenerate.h"
#include "IStreamGenerate.h"

int main()
{
    const size_t matrix_size = 10;
    
    auto m1 = std::make_unique<Matrix>(matrix_size);
    auto g1 = std::make_unique<RandomGenerate>(-100, 100);
    auto t1 = std::make_unique<Task_1>(std::move(m1), std::move(g1));
    t1->populate_matrix();
    std::cout << "Initial matrix Task_1: " << t1->get_matrix_string() << std::endl;
    t1->Task();
    std::cout << "Result matrix Task_1: " << t1->get_matrix_string() << std::endl;
    
    auto m2 = std::make_unique<Matrix>(matrix_size);
    auto g2 = std::make_unique<ConstantGenerate>(7);
    auto t2 = std::make_unique<Task_2>(std::move(m2), std::move(g2), 0, matrix_size);
    t2->populate_matrix();
    std::cout << "Initial matrix Task_2: " << t2->get_matrix_string() << std::endl;
    t2->Task();
    std::cout << "Result matrix Task_2: " << t2->get_matrix_string() << std::endl;
    
    auto m3 = std::make_unique<Matrix>(matrix_size);
    auto g3 = std::make_unique<IStreamGenerate>();
    auto t3 = std::make_unique<Task_3>(std::move(m3), std::move(g3));
    t3->populate_matrix();
    std::cout << "Initial matrix Task_3: " << t3->get_matrix_string() << std::endl;
    t3->Task();
    std::cout << "Result matrix Task_3: " << t3->get_matrix_string() << std::endl;
    
    return 0;
}
