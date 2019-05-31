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
    PlayerClass::Coord& target();
    void placeAll();
    bool attack(PlayerClass&, const Coord&);
public:
    Computer() : PlayerClass(MAPMIN, "Computer") { placeAll(); }
    Computer(const uint8_t size) : PlayerClass(size, "Computer") { placeAll(); }
    
    virtual void place(Mapping) override;
    virtual bool turn(PlayerClass*) override;
};

#endif /* COMPUTER_H */

