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
    std::string shipName(Mapping);
    void copyMap(PlayerClass&);
public:
    Player() : PlayerClass() {}
    Player(const uint8_t size) : PlayerClass(size, "Player") {}
    Player(const uint8_t size, const std::string name) : PlayerClass(size, name) {}
    Player(Player& orig);
    
    virtual void place(Mapping) override;
    virtual bool turn(PlayerClass*) override;
};

#endif /* PLAYE*R_H */

