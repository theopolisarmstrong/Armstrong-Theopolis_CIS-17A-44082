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
    while (input > maxVal){
        std::cout << error << std::endl;
        read(input);
        input = atoi(reinterpret_cast<char*>(&input));
    }
}
void minVal(uint8_t& input, const int minVal, const std::string error){
    while (input < minVal){
        std::cout << error << std::endl;
        read(input);
        input = atoi(reinterpret_cast<char*>(&input));
    }
}
void valid(char& input, const char val1, const char val2, const std::string error){
    while (input != val1 && input != val2){
        std::cout << error << std::endl;
        read(input);
//        input = atoi(reinterpret_cast<char*>(&input));
    }
}
void valid(char& input, const char val1, const char val2, const char val3, const std::string error){
    while (input != val1 && input != val2 && input != val3){
        std::cout << error << std::endl;
        read(input);
//        input = atoi(reinterpret_cast<char*>(&input));
    }
}
void valid(char& input, const char val1, const char val2, const char val3, const char val4, const std::string error){
    while (input != val1 && input != val2 && input != val3 && input != val4){
        std::cout << error << std::endl;
        read(input);
//        input = atoi(reinterpret_cast<char*>(&input));
    }
}
