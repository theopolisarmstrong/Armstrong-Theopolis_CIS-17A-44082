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
const uint8_t SHIPNUM = 3; //Number of available ship types
const char S_FILE[9] = "save.dat"; //Save file name
//Enumerators
enum Mapping {HIT = -2, MISS = -1, PATROL = 1, DESTROY, CARRIER}; //Map indications/ship size/ship health
//Menu choice options/game modes
enum Winner {NO_WIN = -1, P1_WIN, P2_WIN, CPU_WIN = 1}; //Winner of the game
//Structures
struct Header{ //Binary file output header
    uint8_t mapSize = 0;
    uint playNum = 0;
};

//Battleship class
class Battleship{
private:
    struct coord{
        char x = 0;
        char y = 0;
    };
    enum PlayInd {P1, P2, CPU = 1};
    static const uint PLAYNUM; //Number of players
    
    std::vector<PlayerClass*>players;
    uint8_t size = 0; //Map size
    enum Options gameMode = NONE; //game mode chosen in menu
    Winner winner = NO_WIN; //winner of the game
    bool isEnd = false; //Game loop end flag
    
    //Internal game functions
    void title(); //Display title
    char menu(); //Output menu and receives player's menu choice
    void save(); //Save current game status
    
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

