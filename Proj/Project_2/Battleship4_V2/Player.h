/*
 * File:   Player.h
 * Author: Theopolis Armstrong
 * Created on May 29, 2019 4:29 AM
 * Purpose: Human Player class declaration
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "PlayerClass.h"

class Player : public PlayerClass{
private:
    
public:
    Player() : PlayerClass() {}
    Player(const uint8_t size, const char name[]) : PlayerClass(size, name) {}
    Player(const Player& orig) : PlayerClass() {}
};

#endif /* PLAYER_H */

