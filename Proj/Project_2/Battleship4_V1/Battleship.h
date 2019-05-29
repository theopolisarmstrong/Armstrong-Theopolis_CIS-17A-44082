/*
 * File:   Player.h
 * Author: Theopolis Armstrong
 * Created on May 28, 2019 5:05 AM
 * Purpose: Battleship game class declaration
 */

#ifndef BATTLESHIP_H
#define BATTLESHIP_H
#include <iostream>
#include <array>
using namespace std;

//User libraries
#include "Player.h"

//Global constants
const unsigned uint8_t CHARNUM = 48;  //Char constant to integer constant conversion
const unsigned uint SHIPNUM = 3; //Number of available ship types
const unsigned uint8_t NAMELEN = 9; //Maximum length of player name
const char S_FILE[8] = "save.dat"; //Save file name
//Enumerators
enum Mapping {HIT = -2, MISS = -1, PATROL = 1, DESTROY, CARRIER}; //Map indications/ship size/ship health
//Menu choice options/game modes
enum Options {NONE = 0, PVCPU, PVP, LOAD,
                SAVE = (static_cast<int>('s')-CHARNUM),SAVE_S = (static_cast<int>('S')-CHARNUM),
                EXIT = (static_cast<int>('e')-CHARNUM), EXIT_E = (static_cast<int>('E')-CHARNUM)};
enum Winner {NO_WIN = -1, P1_WIN, P2_WIN, CPU_WIN = 1}; //Winner of the game
//Structures
struct Header{ //Binary file output header
    uint8_t mapSize = 0;
    uint playNum = 0;
};

//Battleship class
class Battleship{
private:
    enum PlayInd {P1, P2, CPU = 1};
    static const uint PLAYNUM; //Number of players
    
    vector<Player>players;
    uint8_t size = 0; //Map size
    Options gameMode = NONE; //game mode chosen in menu
    Winner winner = NO_WIN; //winner of the game
    bool isEnd = false; //Game loop end flag
    
    //Internal game functions
    void title(); //Display title
    
public:
    Battleship(char pnum);
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

