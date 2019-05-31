/*
 * File:   Input.cpp
 * Author: Theopolis Armstrong
 * Created on May 31, 2019 3:36 AM
 * Purpose: Input validation function definition
 */

#include <iostream>
using namespace std;

#include "Input.h"
//Validation
void maxVal(uint8_t& input, const int maxVal, const std::string error){
    if (input == EXIT || input == EXIT_E){
        std::cout << "Goodbye!\n";
        exit(0);
    }
    while (input > maxVal && input != EXIT && input != SAVE){
        std::cout << error << std::endl;
        std::cin >> input;
        input = atoi(reinterpret_cast<char*>(&input));
    }
}
void minVal(uint8_t& input, const int minVal, const std::string error){
    if (input == EXIT || input == EXIT_E){
        std::cout << "Goodbye!\n";
        exit(0);
    }
    while (input < minVal && input != EXIT && input != SAVE){
        std::cout << error << std::endl;
        std::cin >> input;
        input = atoi(reinterpret_cast<char*>(&input));
    }
}
void valid(char& input, const char val1, const char val2, const std::string error){
    if (input == EXIT || input == EXIT_E){
        std::cout << "Goodbye!\n";
        exit(0);
    }
    while (input != val1 && input != val2 && input != EXIT && input != SAVE){
        std::cout << error << std::endl;
        std::cin >> input;
        input = atoi(reinterpret_cast<char*>(&input));
    }
}
void valid(char& input, const char val1, const char val2, const char val3, const std::string error){
    if (input == EXIT || input == EXIT_E){
        std::cout << "Goodbye!\n";
        exit(0);
    }
    while (input != val1 && input != val2 && input != val3 && input != EXIT && input != SAVE){
        std::cout << error << std::endl;
        std::cin >> input;
        input = atoi(reinterpret_cast<char*>(&input));
    }
}
void valid(char& input, const char val1, const char val2, const char val3, const char val4, const std::string error){
    if (input == EXIT || input == EXIT_E){
        std::cout << "Goodbye!\n";
        exit(0);
    }
    while (input != val1 && input != val2 && input != val3 && input != val4 && input != EXIT && input != SAVE){
        std::cout << error << std::endl;
        std::cin >> input;
        input = atoi(reinterpret_cast<char*>(&input));
    }
}