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
    void target(Coord&);
    void placeAll();
public:
    Computer();
    Computer(const uint8_t);
    
    virtual void place(Mapping) override;
    virtual bool turn(PlayerClass*) override;
};

#endif /* COMPUTER_H */

