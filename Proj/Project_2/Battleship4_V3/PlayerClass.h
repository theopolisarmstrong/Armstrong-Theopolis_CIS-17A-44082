/*
 * File:   PlayerClass.h
 * Author: Theopolis Armstrong
 * Created on May 29, 2019 3:10 AM
 * Purpose: Virtual Player class declaration
 */

#ifndef PLAYERCLASS_H
#define PLAYERCLASS_H
#include <iostream>

enum Mapping {HIT = -2, MISS = -1, PATROL = 1, DESTROY, CARRIER}; //Map indications/ship size/ship health
const uint8_t MAPMIN = 4; //Minimum map size

class PlayerClass{
protected:
    static const uint8_t NAMELEN; //Maximum length of player name
    char name[9];
    uint8_t size; //Map size
    int8_t **map; //Map status
    uint8_t health[3] = {PATROL, DESTROY, CARRIER}; //Ships health
    
    void initMap();
public:
    //Constructors
    PlayerClass() : size(MAPMIN), name("Player") {}
    PlayerClass(const char n[]) : size(MAPMIN) { strcpy(name, n); }
    PlayerClass(const uint8_t);
    PlayerClass(const uint8_t, const char[]);
    virtual ~PlayerClass();
    //Mutators
    void setSize(uint8_t s) { size = s; }
    void setName(const char n[]) { strcpy(name, n); }
    //Accessors
    uint8_t getSize() const { return size; }
    const char* getName() const { return name; }
    void showMap() const;
    //Overloaded operator
    int8_t* operator[](const int &);
    //Pure virtual functions
    virtual void place(Mapping) = 0;
};

#endif /* PLAYERCLASS_H */

