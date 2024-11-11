/*
 * File:   Computer.h
 * Author: Theopolis Armstrong
 * Created on May 29, 2019 4:39 AM
 * Purpose: Human Player class definition
 */

#ifndef COMPUTER_H
#define COMPUTER_H

#include "PlayerClass.h"
#include <vector>

class Computer : public PlayerClass{
private:
    void target(Coord&);
    void placeAll();
    vector<char> pastX;  //Previous X-axis targets
    vector<char> pastY;  //Previous Y-axis targets
public:
    Computer();
    Computer(const uint8_t);
    
    virtual void place(Mapping) override;
    virtual bool turn(PlayerClass*) override;

    bool enable_debug = false;
};

#endif /* COMPUTER_H */

