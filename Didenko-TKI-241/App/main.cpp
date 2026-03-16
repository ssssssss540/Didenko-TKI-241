#include <iostream>
#include <memory>
#include "Task_1.h"
#include "Task_2.h"
#include "Task_3.h"
#include "InputHandler.h"

int main() {
    try {
    
        const size_t matrix_size = InputHandler::get_matrix_size();
        

        std::cout << "\n--- Task 1: Swap last negative and last positive ---\n";
        auto generator1 = InputHandler::choose_generator();
        auto task1 = std::make_unique<Task_1>(
            std::make_unique<Matrix>(matrix_size),
            std::move(generator1)
        );
        task1->populate_matrix();
        std::cout << "Initial matrix Task_1: " << task1->get_matrix_string() << std::endl;
        task1->Task();
        std::cout << "Result matrix Task_1: " << task1->get_matrix_string() << std::endl;
        
 
        std::cout << "\n--- Task 2: Remove elements in range ---\n";
        auto generator2 = InputHandler::choose_generator();
        auto task2 = std::make_unique<Task_2>(
            std::make_unique<Matrix>(matrix_size),
            std::move(generator2),
            0,
            matrix_size
        );
        task2->populate_matrix();
        std::cout << "Initial matrix Task_2: " << task2->get_matrix_string() << std::endl;
        task2->Task();
        std::cout << "Result matrix Task_2: " << task2->get_matrix_string() << std::endl;
        
      
        std::cout << "\n--- Task 3: Transform elements ---\n";
        auto generator3 = InputHandler::choose_generator();
        auto task3 = std::make_unique<Task_3>(
            std::make_unique<Matrix>(matrix_size),
            std::move(generator3)
        );
        task3->populate_matrix();
        std::cout << "Initial matrix Task_3: " << task3->get_matrix_string() << std::endl;
        task3->Task();
        std::cout << "Result matrix Task_3: " << task3->get_matrix_string() << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}