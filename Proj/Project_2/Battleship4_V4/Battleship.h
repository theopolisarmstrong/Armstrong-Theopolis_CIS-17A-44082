/*
 * File:   Player.h
 * Author: Theopolis Armstrong
 * Created on May 28, 2019 5:05 AM
 * Purpose: Battleship game class declaration
 */

#ifndef BATTLESHIP_H
#define BATTLESHIP_H
#include <iostream>
#include <vector>

//User libraries
#include "PlayerClass.h"
#include "Input.h"


//Structures

//Battleship class
class Battleship{
private:
    struct Header{ //Binary file data header
        uint8_t mapSize = 0;
        uint8_t playNum = 0;
        Options gamemode = NONE;
    };
    struct coord{
        char x = 0;
        char y = 0;
    };
    enum PlayInd {NO_ONE = -1, P1, P2, CPU = 1};
    static const uint8_t PLAYNUM; //Number of players
    
    std::vector<PlayerClass*>players;
    uint8_t size = 0; //Map size
    Options gameMode; //game mode chosen in menu
    PlayInd winner = NO_ONE; //winner of the game
    bool isEnd = false; //Game loop end flag
    
    //Internal game functions
    void title(); //Display title
    char menu(); //Output menu and receives player's menu choice
    void save(); //Save current game status
    void load(); //Initialize game with save file progress
    
public:
    //Constructors
    Battleship(char pnum) : players(pnum) {}
    //Mutators
    void setEnd(bool end) { isEnd = end; }
    //Accessors
    bool getEnd(){ return isEnd; }
    
    void init();
    void loop();
    void end();
};

#endif /* BATTLESHIP_H */

