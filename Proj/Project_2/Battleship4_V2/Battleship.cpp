/*
 * File:   Battleship.cpp
 * Author: Theopolis Armstrong
 * Created on May 28, 2019 5:05 AM
 * Purpose: Battleship game class definition
 */

#include <fstream>
using namespace std;

#include "Battleship.h"
#include "PlayerClass.h"
#include "Input.h"

//Initialize static variables
const uint Battleship::PLAYNUM = 2;

void Battleship::init(){
    
    title();
    while(gameMode == NONE){   //Loop menu until game mode is chosen
        switch(menu()){
            case PVCPU:
                char** map;
                //Initialize game
                cout << "Initializing Player vs. Computer game mode.\nEnter " << static_cast<char>(EXIT_E+48) << " at any time to quit.\n";
                cout << "Enter map size: ";
                cin >> size;
                size = atoi(reinterpret_cast<char*>(&size));
                minVal(size, 4, "Error: Size too low.\nEnter a valid size: ");
                gameMode = PVCPU; //Set game mode
                //Initialize ship arrays
                players[P1] = Player(size, "Player 1");
                players[CPU] = initShip(size);
                //Initialize names
                players[P1] = Player("Player 1");
                players[P2] = Player("Computer");
                
                //Set ship positions
                cout << "Setting CPU ship positions...\n";
                //Place computer player ships
                cpuMap(players[CPU]->ships, size, CARRIER);
                cpuMap(players[CPU]->ships, size, DESTROY);
                cpuMap(players[CPU]->ships, size);
//                map(players[CPU]->ships, size); //Map cpu ship placements for debugging
                //Input and set player ships
                pMap(players[P1], size, CARRIER);
                pMap(players[P1], size, DESTROY);
                pMap(players[P1], size, PATROL);
                cout << endl;
                break;
            case PVP:
                //Initialize game
                cout << "Initializing Player vs. Player game mode.\nEnter a 0 at any time to quit.\n";
                cout << "Enter map size: ";
                cin >> size;
                size = atoi(reinterpret_cast<char*>(&size));
                minVal(size, 4, "Error: Size too low.\n");
                gameMode = PVP; //Set game mode
                //Initialize player structures
                players[P1] = initShip(size);
                players[P2] = initShip(size);
                strlcpy(players[P1]->name, "Player 1", NAMELEN);
                strlcpy(players[P2]->name, "Player 2", NAMELEN);
                
                //Set ship positions
                pMap(players[P1], size, CARRIER);
                pMap(players[P1], size, DESTROY);
                pMap(players[P1], size);
                cout << endl;
                pMap(players[P2], size, CARRIER);
                pMap(players[P2], size, DESTROY);
                pMap(players[P2], size);
                cout << endl;
                break;
            case LOAD:
                load();
                break;
            case EXIT:
            case EXIT_E:
                cout << "Goodbye.\n";
                return 0;
                break;
        }
    }
}

//Gameplay loop
void Battleship::loop(){
    char targetX, targetY;  //Target coordinates
    string hit;   //Indicates a hit
    
    cout << "********\n" <<"*BEGIN!*\n" << "********\n\n";
    cout << "Enter " << static_cast<char>(EXIT_E+CHARNUM) << " at any time to quit.\n";
    //    cout << "Enter " << static_cast<char>(SAVE_S+CHARNUM) << " at any time to save and quit.\n";
    switch(gameMode){
            //Player vs. CPU
        case PVCPU:{
            while(!end){
                //Player turn
                winner = turn(players[CPU], players[P1], size, end);
//                map(players[CPU]->ships, size); //Map CPU ships for debugging
                //Computer Turn
                if (!end){
                    cout << "\nComputer's turn: \n";
                    genTar(targetX, targetY, size);
                    cout << "The computer targets (" << static_cast<int>(targetX) << ", " << static_cast<int>(targetY) << ")." << endl;
                    attack(targetX, targetY, players[P1], players[CPU]) ? hit = "Computer hits!" : hit = "Computer misses!";  //Take computer's turn using random X and Y target coord's [1-size of map]
                    cout << hit << endl;
                    //Test for player loss
                    if (testEnd(players[P1]->ships, size)){
                        end = true;
                        winner = CPU_WIN;
                    }
                }
            }
            break;}
        case PVP:{
            while(!end){
                //Player 1's turn
                winner = turn(players[P2], players[P1], size, end);
                //Player 2 Turn
                if(!end){
                    winner = turn(players[P1], players[P2], size, end);
                }
            }
            break;}
    }
}
    
void Battleship::title(){
    cout << " ____        _   _   _           _     _" << endl;
    cout << "|  _ \\      | | | | | |         | |   (_)" << endl;
    cout << "| |_) | __ _| |_| |_| | ___  ___| |__  _ _ __" << endl;
    cout << "|  _ < / _` | __| __| |/ _ \\/ __| '_ \\| | '_ \\" << endl;
    cout << "| |_) | (_| | |_| |_| |  __/\\__ \\ | | | | |_) |" << endl;
    cout << "|____/ \\__,_|\\__|\\__|_|\\___||___/_| |_|_| .__/" << endl;
    cout << "                                      | |\n";
    cout << "                                      |_|\n";
}

char menu(){
    uint8_t choice = 0;
    cout << "Choose a menu item: \n";
    cout << "1. Player vs. CPU\n";
    cout << "2. Player vs. Player\n";
    cout << "3. Load game from file\n";
    cout << "e. Exit\n";
    
    cin >> choice;
    choice = atoi(reinterpret_cast<char*>(&choice));
    while (choice != PVCPU && choice != PVP && choice != LOAD && choice != SAVE && choice != EXIT && choice != EXIT_E){
        cout << "Error: Invalid menu choice\n";
        cin >> choice;
        choice = atoi(reinterpret_cast<char*>(&choice));
    }
    return choice;
}

void Battleship::save(){
    
}