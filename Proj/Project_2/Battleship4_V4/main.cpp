/*
 * File:   main.cpp
 * Author: Theopolis Armstrong
 * Created on April 14, 2019 12:30 PM
 * Purpose: Project 2 - Battleship 4 V4
 *
 * Title raw ASCII art generated using http://www.patorjk.com/software/taag/
 *
 * Quick init testing values
 * PVCPU: 1 4 v 3 2 n h 1 2 n 1 1 n
 * PVP: 2 4 v 3 2 n h 1 2 n 1 1 n 4 v 3 2 n h 1 2 n 1 1 n
 */

//System Libraries

//User Libraries
#include "Battleship.h"
using namespace std;

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Structures

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    Battleship game(2);
    
    //Initialize game
    game.init();
    
    //Gameplay loop
    game.loop();
    
    game.end();
    //Exit stage right or left!
    return 0;
}