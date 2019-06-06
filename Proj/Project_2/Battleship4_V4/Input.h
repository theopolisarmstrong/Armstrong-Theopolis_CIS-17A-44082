/*
 * File:   Input.h
 * Author: Theopolis Armstrong
 * Created on May 28, 2019 10:39 AM
 * Purpose: Input validation function declaration
 */

#ifndef INPUT_H
#define INPUT_H

enum Options {NONE = 0, PVCPU = '1', PVP = '2', LOAD = '3', EXIT = 'e', EXIT_E = 'E'};

template<class T>
void read(T &input){
    std::cin >> input;
    if (input == EXIT || input == EXIT_E){
        std::cout << "Goodbye!\n";
        exit(0);
    }
}
//Input validation
void maxVal(uint8_t&, const int, const std::string);
void minVal(uint8_t&, const int, const std::string);
void valid(char&, const char, const char, const std::string);
void valid(char&, const char, const char, const char, const std::string);
void valid(char&, const char, const char, const char, const char, const std::string);

#endif /* INPUT_H */

