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
using namespace std;

//User libraries
//#include "Player.h"

//Global constants
const unsigned char CHARNUM = 48;   //Char constant to integer constant conversion
const unsigned char SHIPNUM = 3; //Number of available ship types
const unsigned char NAMELEN = 9; //Maximum length of player name
const string S_FILE = "save.dat"; //Save file name
//Enumerators
enum Mapping {HIT = -2, MISS = -1, PATROL = 1, DESTROY, CARRIER}; //Map indications/ship size/ship health
enum Options {NONE = 0, PVCPU, PVP, LOAD, SAVE = (static_cast<int>('s')-CHARNUM), SAVE_S = (static_cast<int>('S')-CHARNUM), EXIT = (static_cast<int>('e')-CHARNUM), EXIT_E = (static_cast<int>('E')-CHARNUM)}; //Menu choice options/game modes
enum Winner {NO_WIN = -1, P1_WIN, P2_WIN, CPU_WIN = 1}; //Winner of the game

//Battleship class
class Battleship{
private:
    bool isEnd = false;
//    vector<Player>players;
    
    void title(); //Display title 
public:
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

