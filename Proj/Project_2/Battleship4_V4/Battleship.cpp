/*
 * File:   Battleship.cpp
 * Author: Theopolis Armstrong
 * Created on May 28, 2019 5:05 AM
 * Purpose: Battleship game class definition
 */

#include <iostream>
#include <fstream> //File I/O operations
#include <cstdio> //exit fucntion
#include <queue>
#include <algorithm>
#include <list>

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
            case PVCPU: {
              //Initialize game
              gameMode = PVCPU; //Set game mode

              cout << "Initializing Player vs. Computer game mode.\n";
              cout << "Enter " << static_cast<char>(EXIT_E) << " at any time to quit.\n";
              cout << "Enter map size: ";
              read(size);
              size = atoi(reinterpret_cast<char *>(&size));
              minVal(size, 4, "Error: Size too low.\nEnter a valid size: ");
              //Initialize players
              auto cpu = new Computer(size);
              cpu->setName("CPU 1");
              cpu->enable_debug = true;
              auto player = new Player(size, "Player 1");
              try {
                players[cpu->getName()] = cpu;
                players[player->getName()] = player;
              }
              catch (bad_alloc) {
                cout << "Error: Memory allocation failure.\n";
                exit(0);
              }
              place_ships();
            } break;

            case PVP: {
              //Initialize game
              int numPLayers = 2;
              gameMode = PVP; //Set game mode

              cout << "Initializing Player vs. Player game mode.\n";
              cout << "Enter map size: ";
              read(size);
              size = atoi(reinterpret_cast<char *>(&size));
              minVal(size, 4, "Error: Size too low.\n");

              //Initialize player structures
              for (size_t i = 0; i < numPLayers; i++) {
                std::string name;
                std::cout << "Enter player " << i << "1's name: ";
                getline(cin, name);
                try {
                  auto player = new Player(size, name);
                }
                catch (bad_alloc) {
                  cout << "Error: Memory allocation failure.\n";
                  exit(0);
                }
              }
              place_ships();
            } break;

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
    cout << "Enter " << static_cast<char>(EXIT_E) << " at any time to quit.\n";
    cout << "Progress will be saved every turn.\n";

    std::queue<PlayerClass*> q;
    std::for_each(players.begin(), players.end(), [&](auto p){ q.push(p.second); });

    while(!isEnd){
      auto player = q.front();
      q.pop();
      q.push(player);
      cout << "\n" << player->getName() << "'s turn: \n";
      if(player->turn(q.front())){
          isEnd = true;
          winner = player;
      }
      save();
    }
}
void Battleship::end(){
    cout << endl << winner->getName() << " wins!\n";
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
    for (auto [name, player] : players){
        //Save name
        unsigned long nameSize = name.size();
        saveFile.write(reinterpret_cast<char*>(&nameSize), sizeof(nameSize)); //Write name length
        saveFile.write(&name[0], nameSize); //Write name
        //Save map
        for (int x = 0; x < header.mapSize; x++){
            saveFile.write(reinterpret_cast<char*>((*player)[x]), sizeof((*player)[x]) * header.mapSize);
        }
        //Save health
        for (int x = 0; x < player->getShipNum(); x++){
            uint8_t health = player->getHealth(x);
            saveFile.write(reinterpret_cast<char*>(&health), sizeof(health));
        }
    }
    saveFile.close();
}
void Battleship::load(){
    Header header;
    fstream saveFile(S_FILE, fstream::binary | fstream::in);
    if (saveFile){
        string name = "Name read error";
        //Read header information
        cout << "Reading save file...\n";
        saveFile.read(reinterpret_cast<char*>(&header), sizeof(header));
        std::list<PlayerClass*> pList;
        for (int i = 0; i < header.playNum; i++){
            if (header.gamemode == PVCPU && i == header.playNum - 1){ //Initialize computer player at end of players vector
                try{
                    auto cpu = new Computer(header.mapSize);
                    cpu->setName("CPU 1");
                    pList.push_back(cpu);
                }
                catch (bad_alloc){
                    cout << "Error: Memory allocation failure while loading\n";
                    exit(EXIT_FAILURE);
                }
            }else{
              try{
                auto player = new Player(header.mapSize);
                players[player->getName()] = player;
                pList.push_back(player);
              }
                catch (bad_alloc){
                    cout << "Error: Memory allocation failure while loading\n";
                    exit(EXIT_FAILURE);
                }
            }
        }
        for (auto it = pList.begin(); it != pList.end(); it++) {
          auto player = *it;
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
            player->setName(name); //Set name
            //Read map
            for (int x = 0; x < header.mapSize; x++){
                saveFile.read(reinterpret_cast<char*>((*player)[x]), sizeof((*player)[x]) * header.mapSize);
            }
            //Read health
            for (int x = 0; x < player->getShipNum(); x++){
                uint8_t health = 0;
                saveFile.read(reinterpret_cast<char*>(&health), sizeof(health));
                player->setHealth(x, health);
            }
        }
        //Initialize game
        cout << "Initializing game...\n";
        size = header.mapSize;
        gameMode = header.gamemode; //Set gamemode; ends menu loop/begins game
        //Close file
        saveFile.close();
    } else cout << "Error: No existing save file\n";
}

void Battleship::place_ships() {
  for (auto it = players.begin(); it != players.end(); it++) {
    it->second->place(CARRIER);
    it->second->place(DESTROY);
    it->second->place(PATROL);
  }
  cout << endl;
}
