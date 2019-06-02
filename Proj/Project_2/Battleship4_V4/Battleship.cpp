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
const char Battleship::S_FILE[9] = "save.dat";

//Main game functions
void Battleship::init(){
    title();
    while(gameMode == NONE){   //Loop menu until game mode is chosen
        switch(menu()){
            case PVCPU:
                //Initialize game
                cout << "Initializing Player vs. Computer game mode.\n";
                cout << "Enter " << static_cast<char>(EXIT_E) << " at any time to quit.\n";
                cout << "Enter map size: ";
                read(size);
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
                //Ship placements moved to Computer player class constructor
//                players[CPU]->showMap(); //Map cpu ship placements for debugging
                //Input and set player ships
                players[P1]->place(CARRIER);
                players[P1]->place(DESTROY);
                players[P1]->place(PATROL);
                cout << endl;
                break;
            case PVP:
                //Initialize game
                cout << "Initializing Player vs. Player game mode.\n";
                cout << "Enter map size: ";
                read(size);
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
                //WIP
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
void Battleship::loop(){
    cout << "\n********\n" <<"*BEGIN!*\n" << "********\n\n";
    switch(gameMode){
            //Player vs. CPU
        case PVCPU:{
            while(!isEnd){
                //Player turn
                cout << "\n" << players[P1]->getName() << "'s turn: \n";
                if(players[P1]->turn(players[CPU])){
                    isEnd = true;
                    winner = P1;
                }
                save();
//                players[CPU]->debugMap(); //Map CPU ships for debugging
                //Computer Turn
                if (!isEnd){
                    cout << "\n" << players[CPU]->getName() << "'s turn: \n";
                    if (players[CPU]->turn(players[P1])){
                        isEnd = true;
                        winner = CPU;
                    }
                }
                save();
            }
            break;}
        case PVP:{
            while(!isEnd){
                //Player 1's turn
                cout << players[P1]->getName() << "'s turn: \n";
                if(players[P1]->turn(players[P2])){
                    isEnd = true;
                    winner = P1;
                }
                save();
                //Player 2 Turn
                if(!isEnd){
                    cout << "\n" << players[P2]->getName() << "'s turn: \n";
                    if(players[P2]->turn(players[P1])){
                        isEnd = true;
                        winner = P2;
                    }
                }
                save();
            }
            break;}
    }
}
void Battleship::end(){
    cout << endl << players[winner]->getName() << " wins!\n";
}

//Internal game functions
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
    
    read(choice);
    while (choice != PVCPU && choice != PVP && choice != LOAD){
        cout << "Error: Invalid menu choice\n";
        read(choice);
    }
    return choice;
}
void Battleship::save(){
    Header header = {
        size,
        players.size(),
        gameMode
    };
    fstream saveFile(S_FILE, fstream::binary | fstream::out);
    saveFile.write(reinterpret_cast<char*>(&header), sizeof(header)); //Write save file header information
    //Save player data
    for (auto i : players){
        //Save name
        string name = i->getName();
        unsigned long nameSize = name.size();
        saveFile.write(reinterpret_cast<char*>(&nameSize), sizeof(nameSize)); //Write name length
        saveFile.write(&name[0], nameSize); //Write name
        //Save map
        for (int x = 0; x < header.mapSize; x++){
            saveFile.write(reinterpret_cast<char*>(i->operator[](x)), sizeof(i->operator[](x)) * header.mapSize);
        }
        //Save health
        for (int x = 0; x < i->getShipNum(); x++){
            uint8_t health = i->getHealth(x);
            saveFile.write(reinterpret_cast<char*>(&health), sizeof(health));
        }
    }
    saveFile.close();
}
void Battleship::load(){
    Header header;
    fstream saveFile(S_FILE, fstream::binary | fstream::in);
    string name = "Name read error";
    //Read header information
    cout << "Reading save file...\n";
    saveFile.read(reinterpret_cast<char*>(&header), sizeof(header));
    players.resize(header.playNum);
    for (int i = 0; i < header.playNum; i++){
        if (header.gamemode == PVCPU && i == header.playNum - 1){ //Initialize computer player at end of players vector
            cout << "Initializing CPU Player...\n";
            try{
                players[i] = new Computer(header.mapSize);
            }
            catch (bad_alloc){
                cout << "Error: Memory allocation failure while loading\n";
                exit(EXIT_FAILURE);
            }
        }else{
            cout << "Initializing Player " << i+1 << "...\n";
            try{
                players[i] = new Player(header.mapSize, name);
            }
            catch (bad_alloc){
                cout << "Error: Memory allocation failure while loading\n";
                exit(EXIT_FAILURE);
            }
        }
    }
    for (auto i : players){
        //Read name
        unsigned long nameSize = 0;
        string name = "No name read";
        saveFile.read(reinterpret_cast<char*>(&nameSize), sizeof(unsigned long)); //Read name length
        try{
            name.resize(nameSize);
        }
        catch (bad_alloc){
            cout << "Error: String resize error\n";
            exit(EXIT_FAILURE);
        }
        saveFile.read(&name[0], sizeof(char) * nameSize); //Read name
        i->setName(name); //Set name
        //Read map
        for (int x = 0; x < header.mapSize; x++){
            saveFile.read(reinterpret_cast<char*>(i->operator[](x)), sizeof(i->operator[](x)) * header.mapSize);
        }
        //Read health
        for (int x = 0; x < i->getShipNum(); x++){
            uint8_t health = 0;
            saveFile.read(reinterpret_cast<char*>(&health), sizeof(health));
            i->setHealth(x, health);
        }
    }
    //Initialize game
    cout << "Initializing game...\n";
    size = header.mapSize;
    gameMode = header.gamemode; //Set gamemode; ends menu loop/begins game
    cout << "Gamemode: " << gmString(gameMode) << endl;
    //Close file
    saveFile.close();
}
string Battleship::gmString(Options gm) const {
    string str = "";
    switch(gm){
        case NONE:
            str = "None";
            break;
        case PVCPU:
            str = "Player vs. Computer";
            break;
        case PVP:
            str = "Player vs. Player";
            break;
        case LOAD:
            str = "Load save";
            break;
    }
    return str;
}
