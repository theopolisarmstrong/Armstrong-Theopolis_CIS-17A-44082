/*
 * File:   Validation.h
 * Author: Theopolis Armstrong
 * Created on May 28, 2019 10:39 AM
 * Purpose: Input validation functions
 */

#ifndef VALIDATION_H
#define VALIDATION_H
#include <iostream>
#include <cstdlib>

enum Options {NONE = 0, PVCPU, PVP, LOAD,
                SAVE = ('s' - 48), SAVE_S = ('S' - 48),
                EXIT = ('e' - 48), EXIT_E = ('E' - 48)};

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

#endif /* VALIDATION_H */

