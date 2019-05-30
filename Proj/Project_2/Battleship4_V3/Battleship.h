/*
 * File:   Player.h
 * Author: Theopolis Armstrong
 * Created on May 28, 2019 5:05 AM
 * Purpose: Battleship game class declaration
 */

#ifndef BATTLESHIP_H
#define BATTLESHIP_H
#include <vector>

//User libraries
#include "PlayerClass.h"
#include "Input.h"

//Global constants
const char S_FILE[9] = "save.dat"; //Save file name
//Enumerators

//Structures
struct Header{ //Binary file output header
    uint8_t mapSize = 0;
    uint playNum = 0;
    Options gamemode = NONE;
};

//Battleship class
class Battleship{
private:
    struct coord{
        char x = 0;
        char y = 0;
    };
    enum PlayInd {NONE = -1, P1, P2, CPU = 1};
    static const uint8_t PLAYNUM; //Number of players
    
    std::vector<PlayerClass*>players;
    uint8_t size = 0; //Map size
    Options gameMode = NONE; //game mode chosen in menu
    PlayInd winner = NONE; //winner of the game
    bool isEnd = false; //Game loop end flag
    
    //Internal game functions
    void title(); //Display title
    char menu(); //Output menu and receives player's menu choice
    void save(); //Save current game status
    void load(); //Initialize game with save file progress
    
public:
    Battleship(char pnum) : players(pnum) {}
    //Mutators
    void setEnd(bool end) { isEnd = end; }
    //Accessors
    bool getEnd(){ return isEnd; }
//    Player getPlayers(char i){ return players[i]; }
    
    void init();
    void loop();
    void end();
};

#endif /* BATTLESHIP_H */

