/*
 * File:   Input.h
 * Author: Theopolis Armstrong
 * Created on May 28, 2019 10:39 AM
 * Purpose: Input validation function declaration
 */

#ifndef INPUT_H
#define INPUT_H

enum Options {NONE = 0, PVCPU, PVP, LOAD,
                SAVE = ('s' - 48), SAVE_S = ('S' - 48),
                EXIT = ('e' - 48), EXIT_E = ('E' - 48)};

//Input validation
void maxVal(uint8_t&, const int, const std::string);
void minVal(uint8_t&, const int, const std::string);
void valid(char&, const char, const char, const std::string);
void valid(char&, const char, const char, const char, const std::string);
void valid(char&, const char, const char, const char, const char, const std::string);

#endif /* INPUT_H */

