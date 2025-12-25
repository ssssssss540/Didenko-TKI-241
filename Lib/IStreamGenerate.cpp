#include <limits>
#include <stdexcept>
#include <iostream>
#include "IStreamGenerate.h"

int IStreamGenerate::generate_number() {
    int num = get_integer_input("Enter number:");
    return num;
}

int IStreamGenerate::get_integer_input(const std::string& prompt) {
    if (!prompt.empty()) {
        std::cout << prompt;
    }

    int input_val;
    input_stream >> input_val;

    if (input_stream.eof()) {
        throw std::runtime_error("Input stream ended");
    }

    if (input_stream.fail()) {
        throw std::invalid_argument("Input must be integer");
    }

    char next_char = input_stream.peek();
    if (next_char != std::char_traits<char>::eof() &&
        next_char != ' ' && next_char != '\t' && next_char != '\n') {
        throw std::invalid_argument("Extra characters after number");
    }

    input_stream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return input_val;
}
