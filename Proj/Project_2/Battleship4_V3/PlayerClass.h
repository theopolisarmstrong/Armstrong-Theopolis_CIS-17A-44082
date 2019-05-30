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
    static const uint8_t SHIPNUM; //Number of available ship types
    struct Coord{
        uint8_t x = 0;
        uint8_t y = 0;
    };
    static const uint8_t NAMELEN; //Maximum length of player name
    
    char name[9];
    uint8_t size; //Map size
    int8_t **map; //Map status
    uint8_t health[3] = {PATROL, DESTROY, CARRIER}; //Ships health
    
    void initMap();
    bool testEnd(PlayerClass&);
    
    //Pure virtual functions
    virtual bool attack(PlayerClass&, const Coord&) = 0;
public:
    //Constructors
    PlayerClass();
    PlayerClass(const char[]);
    PlayerClass(const uint8_t);
    PlayerClass(const uint8_t, const char[]);
    virtual ~PlayerClass();
    
    //Mutators
    void setSize(uint8_t s) { size = s; }
    void setName(const char n[]) { strcpy(name, n); }
    void setHealth(const uint8_t ship, const uint8_t value) { health[ship] = value; }
    
    //Accessors
    uint8_t getSize() const { return size; }
    const char* getName() const { return name; }
    void showMap() const;
    uint8_t getHealth(const uint8_t shipType) const { return health[shipType-1]; }
    
    //Overloaded operator
      int8_t* operator[](const int &);
//    int8_t& operator()(const int&, const int&);
    
    //Pure virtual functions
    virtual void place(Mapping) = 0;
    virtual bool turn(PlayerClass&) = 0;
};

#endif /* PLAYERCLASS_H */
