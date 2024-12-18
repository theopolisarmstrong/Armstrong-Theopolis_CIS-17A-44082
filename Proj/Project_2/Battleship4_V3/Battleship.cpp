/*
 * File:   Battleship.cpp
 * Author: Theopolis Armstrong
 * Created on May 28, 2019 5:05 AM
 * Purpose: Battleship game class definition
 */

#include <iostream>
#include <fstream> //File I/O operations
#include <cstdio> //exit fucntion
using namespace std;

#include "Battleship.h"
#include "Computer.h"
#include "Player.h"


//Initialize static variables
const uint8_t
 Battleship::PLAYNUM = 2;

void Battleship::init(){
    title();
    while(gameMode == NONE){   //Loop menu until game mode is chosen
        switch(menu()){
            case PVCPU:
                //Initialize game
                cout << "Initializing Player vs. Computer game mode.\nEnter " << static_cast<char>(EXIT_E+48) << " at any time to quit.\n";
                cout << "Enter map size: ";
                cin >> size;
                size = atoi(reinterpret_cast<char*>(&size));
                minVal(size, 4, "Error: Size too low.\nEnter a valid size: ");
                gameMode = PVCPU; //Set game mode
                //Initialize players
                try{
                    players[CPU] = new Computer(size);
                    players[P1] = new Player(size, "Player 1");
                }
                catch (bad_alloc){
                    cout << "Error: Memory allocation failure.\n";
                    exit(0);
                }
                
                //Set ship positions
                cout << "Setting CPU ship positions...\n";
                //Place computer player ships
//                players[CPU]->placeAll();
                players[CPU]->place(CARRIER);
                players[CPU]->place(DESTROY);
                players[CPU]->place(PATROL);
//                map(players[CPU]->ships, size); //Map cpu ship placements for debugging
                //Input and set player ships
                players[P1]->place(CARRIER);
                players[P1]->place(DESTROY);
                players[P1]->place(PATROL);
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
                players[P1] = new Player(size, "Player 1");
                players[P2] = new Player(size, "Player 2");
                
                //Set ship positions
                players[P1]->place(CARRIER);
                players[P1]->place(DESTROY);
                players[P1]->place(PATROL);
                cout << endl;
                players[P2]->place(CARRIER);
                players[P2]->place(DESTROY);
                players[P2]->place(PATROL);
                cout << endl;
                break;
            case LOAD:
                load();
                break;
            case EXIT:
            case EXIT_E:
                cout << "Goodbye.\n";
                exit(0);
                break;
        }
    }
}

//Gameplay loop
void Battleship::loop(){
    
    cout << "********\n" <<"*BEGIN!*\n" << "********\n\n";
    cout << "Enter " << static_cast<char>(EXIT_E+48) << " at any time to quit.\n";
    cout << "Enter " << static_cast<char>(SAVE_S+48) << " at any time to save and quit.\n";
    switch(gameMode){
            //Player vs. CPU
        case PVCPU:{
            while(!isEnd){
                //Player turn
                if(players[P1]->turn(players[CPU])){
                    isEnd = true;
                    winner = P1;
                }
//                map(players[CPU]->ships, size); //Map CPU ships for debugging
                //Computer Turn
                if (!isEnd){
                    cout << "\nComputer's turn: \n";
                    if (players[CPU]->turn(players[P1])){
                        isEnd = true;
                        winner = CPU;
                    }
                }
            }
            break;}
        case PVP:{
            while(!isEnd){
                //Player 1's turn
                if(players[P1]->turn(players[P2])){
                    isEnd = true;
                    winner = P1;
                }
                //Player 2 Turn
                if(!isEnd){
                    if(players[P2]->turn(players[P1])){
                        isEnd = true;
                        winner = P2;
                    }
                }
            }
            break;}
    }
}

void Battleship::end(){
    cout << players[winner]->getName() << " wins!\n";
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

char Battleship::menu(){
    char choice = 0;
    cout << "Choose a menu item: \n";
    cout << "1. Player vs. CPU\n";
    cout << "2. Player vs. Player\n";
    cout << "3. Load game from file\n";
    cout << "e. Exit\n";
    
    cin >> choice;
    choice = atoi(&choice);
    while (choice != PVCPU && choice != PVP && choice != LOAD && choice != SAVE && choice != EXIT && choice != EXIT_E){
        cout << "Error: Invalid menu choice\n";
        cin >> choice;
        choice = atoi(reinterpret_cast<char*>(&choice));
    }
    return choice;
}

void Battleship::save(){
    
}

void Battleship::load(){
    
}