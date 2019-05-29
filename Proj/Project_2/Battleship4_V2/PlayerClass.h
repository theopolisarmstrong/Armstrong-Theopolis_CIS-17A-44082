/*
 * File:   PlayerClass.h
 * Author: Theopolis Armstrong
 * Created on May 29, 2019 3:10 AM
 * Purpose: Virtual Player class declaration
 */

#ifndef PLAYERCLASS_H
#define PLAYERCLASS_H
#include <iostream>

class PlayerClass{
protected:
    enum HEALTH {PATROL = 1, DESTORY, CARRIER};
    static const uint8_t NAMELEN; //Maximum length of player name
    char name[9];
    uint8_t size; //Map size
    uint8_t **map; //Ship status
    uint8_t health[]; //Ships health
    
    void initMap();
public:
    PlayerClass() : size(0), map(nullptr) {}
    PlayerClass(const uint8_t, const char[]);
    virtual ~PlayerClass();
    void getName(const char* n) const { n = name; }
    virtual bool turn() = 0;
};

#endif /* PLAYERCLASS_H */

