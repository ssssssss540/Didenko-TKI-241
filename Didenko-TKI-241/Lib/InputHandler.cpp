#include "InputHandler.h"

int InputHandler::get_integer_input(const std::string& prompt) {
    std::cout << prompt;
    int value;
    while (!(std::cin >> value)) {
        std::cout << "Invalid input. Please enter an integer: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return value;
}

int InputHandler::get_positive_integer(const std::string& prompt) {
    int number = get_integer_input(prompt);
    
    if (number < 0) {
        std::cerr << "Error: Size must be non-negative" << std::endl;
        exit(1);
    }
    
    return number;
}

std::unique_ptr<Generator> InputHandler::choose_generator() {
    std::cout << "\nChoose matrix filling method:\n";
    std::cout << "1. Random values\n";
    std::cout << "2. Constant value\n";
    std::cout << "3. Manual input\n";
    
    int choice = get_integer_input("Enter your choice (1-3): ");
    
    switch (choice) {
        case 1: {
            std::cout << "\nEnter range for random values:\n";
            int lower = get_integer_input("Enter lower bound: ");
            int upper = get_integer_input("Enter upper bound: ");
            return std::make_unique<RandomGenerate>(lower, upper);
        }
        case 2: {
            int constant = get_integer_input("Enter constant value: ");
            return std::make_unique<ConstantGenerate>(constant);
        }
        case 3: {
            return std::make_unique<IStreamGenerate>();
        }
        default: {
            std::cerr << "Error: Invalid choice" << std::endl;
            exit(1);
        }
    }
}

size_t InputHandler::get_matrix_size() {
    return static_cast<size_t>(get_positive_integer("Input matrix size: "));
}