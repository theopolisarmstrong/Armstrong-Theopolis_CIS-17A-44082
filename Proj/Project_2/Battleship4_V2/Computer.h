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
public:
    Computer();
    Computer(const Computer& orig);
    virtual ~Computer();
private:

};

#endif /* COMPUTER_H */

