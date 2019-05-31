/*
 * File:   main.cpp
 * Author: Theopolis Armstrong
 * Created on April 14, 2019 12:30 pM
 * Purpose: Project 2 - Battleship 4 V1
 *
 * Title raw ASCII art generated using http://www.patorjk.com/software/taag/
 */

//System Libraries

//User Libraries
#include "Battleship.h"
using namespace std;

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Structures

//Function Prototypes

//void saveProg(const Player*, const Player*); //Save game progress to file
//Options loadProg(Player*, Player*); //Initialize game w/ data from file
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

//void save(const Player* p1){
//    fstream file(S_FILE, ios::out | ios::binary);
//    file.write(reinterpret_cast<const char*>(&p1->name), NAMELEN);
//    file.write(reinterpret_cast<const char*>(&p1->health), SHIPNUM);
//}
//void load(){
//    fstream file(S_FILE, ios::in | ios::binary);
//    char name[NAMELEN], health[SHIPNUM], total = 0;
//    
//    if(!file){ //Ensure file opened correctly
//        cout << "Error loading file";
//    } else {
//        file.read(reinterpret_cast<char*>(&name), NAMELEN);
//        file.read(reinterpret_cast<char*>(&health), SHIPNUM);
//        
//        //Calculate health total
//        for (char i = 0; i < SHIPNUM; i++)
//            total+=health[i];
//        
//        cout << name << " won the game with " << static_cast<int>(total) << " health remaining!\n";
//    }
//}

//Quick init testing values
//1 4 v 2 1 n h 4 3 n v 1 1 n 1 1 n
//1 4 v 3 2 n h 1 2 n 1 1 n
