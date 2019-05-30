/*
 * File:   Computer.h
 * Author: Theopolis Armstrong
 * Created on May 29, 2019 4:39 AM
 * Purpose: Human Player class definition
 */

#ifndef COMPUTER_H
#define COMPUTER_H

#include "PlayerClass.h"

class Computer : public PlayerClass{
private:
    void genPlace();
public:
    Computer() : PlayerClass(MAPMIN, "Computer") {}
    Computer(const uint8_t size) : PlayerClass(size, "Computer") {}
    Computer(const Computer& orig) : PlayerClass() {}
    
    void place();
};

#endif /* COMPUTER_H */

