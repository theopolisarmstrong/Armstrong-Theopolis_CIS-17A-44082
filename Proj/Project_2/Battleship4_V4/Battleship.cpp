/*
 * File:   Battleship.cpp
 * Author: Theopolis Armstrong
 * Created on May 28, 2019 5:05 AM
 * Purpose: Battleship game class definition
 */

#include <iostream>
#include <fstream> //File I/O operations
#include <cstdio> //exit fucntion
#include <deque>
#include <queue>
#include <algorithm>
#include <list>
#include <random>

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
              gameMode = PVCPU; //Set game mode
              cout << "Selected Player vs. Computer mode!\n";
              setup();
            } break;

            case PVP: {
              //Initialize game
              gameMode = PVP; //Set game mode
              cout << "Initializing Player vs. Player game mode.\n";
              setup();
            } break;

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

void Battleship::setup() {
  cout << "Enter " << static_cast<char>(EXIT_E) << " at any time to quit.\n";
  cout << "Enter map size: ";
  read(size);
  size = atoi(reinterpret_cast<char *>(&size));
  minVal(size, 4, "Error: Size too low.\nEnter a valid size: ");

  //Initialize players
  cout << "Enter the number of players: ";
  read(numPlayers);
  

  for (size_t i = 0; i < numPlayers; i++) {
    PlayerClass* player;
    try {
      if (i == 0 && gameMode == PVCPU) {
        // Add CPU player
        player = new Computer(size);
        player->setName("CPU");
        dynamic_cast<Computer*>(player)->enable_debug = true;
      } else {
        do {
          // Add human player
          std::string name;
          std::cout << "Enter player name: ";
          std::cin >> name;
          player = new Player(size, name);
        } while (std::find_if(players.begin(), players.end(), [&](const PlayerClass* p) { return p->getName() == player->getName(); }) != players.end());
      }

      players.emplace(player);
    }
    catch (bad_alloc) {
      cout << "Error: Memory allocation failure.\n";
      exit(0);
    }
  }

  place_ships();
}

void Battleship::loop(){
    cout << "\n********\n" <<"*BEGIN!*\n" << "********\n\n";
    cout << "Enter " << static_cast<char>(EXIT_E) << " at any time to quit.\n";
    cout << "Progress will be saved every turn.\n";

    // Create shuffled player queue
    std::deque<PlayerClass*> pDeque;
    std::copy(players.cbegin(), players.cend(), std::back_inserter(pDeque));

    // Display players
    std::sort(pDeque.begin(), pDeque.end());
    std::cout << "Player list:\n";
    for (const auto player : pDeque) {
      cout << player->getName() << std::endl;
    }

    // Shuffle players
    std::shuffle(pDeque.begin(), pDeque.end(), std::mt19937(std::random_device()()));

    // Display turn order
    std::cout << "\nTurn order:\n";
    for (const auto player : pDeque) {
      cout << player->getName() << std::endl;
    }

    // Begin gameplay
    std::queue<PlayerClass*> q(pDeque);
    while(!isEnd){
      auto player = q.front();
      q.pop();
      q.push(player);
      cout << "\n" << player->getName() << "'s turn: \n";
      cout << (*min_element(players.begin(), players.end()))->getName() << " is in the lead!\n";
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
    for (auto player : players){
        //Save name
        std::string name = player->getName();
        unsigned long nameSize = name.size();
        saveFile.write(reinterpret_cast<char*>(&nameSize), sizeof(nameSize)); //Write name length
        saveFile.write(&name[0], nameSize); //Write name
        //Save map
        for (int x = 0; x < header.mapSize; x++){
            saveFile.write(reinterpret_cast<char*>((*player)[x]), sizeof((*player)[x]));
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

        for (int i = 0; i < header.playNum; i++) {
          PlayerClass *player;
          try {
            if (header.gamemode == PVCPU && i == 0) { //Initialize computer player
              player = new Computer(header.mapSize);
            } else {
              player = new Player(header.mapSize);
            }
            pList.push_back(player);
          }
          catch (bad_alloc) {
            cout << "Error: Memory allocation failure while loading\n";
            exit(EXIT_FAILURE);
          }
        }

        for (auto it = pList.begin(); it != pList.end(); it++) {
          auto player = *it;
            //Read name
            unsigned long nameSize = 0;
            string name = "No name";
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
                saveFile.read(reinterpret_cast<char*>((*player)[x]), sizeof((*player)[x]));
            }
            //Read health
            for (int x = 0; x < player->getShipNum(); x++){
                uint8_t health = 0;
                saveFile.read(reinterpret_cast<char*>(&health), sizeof(health));
                player->setHealth(x, health);
            }
        }

        std::copy(pList.begin(), pList.end(), std::inserter(players, players.begin()));

      //Close file
      saveFile.close();
        //Initialize game
        cout << "Initializing game...\n";
        size = header.mapSize;
        gameMode = header.gamemode; //Set gamemode; ends menu loop/begins game
    } else cout << "Error: No existing save file\n";
}

void Battleship::place_ships() {
  for (auto player : players) {
    player->place(CARRIER);
    player->place(DESTROY);
    player->place(PATROL);
  }
  cout << endl;
}
