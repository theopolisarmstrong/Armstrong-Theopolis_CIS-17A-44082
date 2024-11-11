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
#include <unordered_map>

//User libraries
#include "PlayerClass.h"
#include "Input.h"

//Battleship class
class Battleship{
private:
    static const char S_FILE[9]; //Save file name
    struct Header{ //Binary file data header
        uint8_t mapSize = 0;
        unsigned long playNum = 0; //Number of players
        Options gamemode = NONE;
        int saveFileVer = 1; //Save file header version
    };
    struct coord{
        char x = 0;
        char y = 0;
    };

    std::unordered_map<std::string, PlayerClass*>players;
    uint8_t size = 0; //Map size
    Options gameMode = NONE; //game mode chosen in menu
    PlayerClass* winner = nullptr; //winner of the game
    bool isEnd = false; //Game loop end flag
    
    //Internal game functions
    void title(); //Display title
    char menu(); //Output menu and receives player's menu choice
    void save(); //Save current game status
    void load(); //Initialize game with save file progress
    void place_ships(); //Prompt players for ship placements

public:
    //Mutators
    void setEnd(bool end) { isEnd = end; }
    //Accessors
    bool getEnd() { return isEnd; }
    
    void init();
    void loop();
    void end();
};

#endif /* BATTLESHIP_H */

