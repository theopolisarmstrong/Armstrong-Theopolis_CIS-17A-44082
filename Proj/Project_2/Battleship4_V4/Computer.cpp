/*
 * File:   Computer.cpp
 * Author: Theopolis Armstrong
 * Created on May 29, 2019 4:39 AM
 * Purpose: Human Player class definition
 */
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

#include "Computer.h"

Computer::Computer() : PlayerClass(MAPMIN, "Computer"){
    srand(time(0));
    placeAll();
}
Computer::Computer(const uint8_t size) : PlayerClass(size, "Computer") {
    srand(time(0));
    placeAll();
}

void Computer::placeAll(){
    place(PATROL);
    place(DESTROY);
    place(CARRIER);
}

void Computer::place(Mapping type){
    char posX;  //Starting X-axis position of each ship
    char posY;  //Starting Y-axis position of each ship
    bool unique = false;

    if (rand()%2){ //Determine orientation of the ship
        //Vertical
        posX = rand()%size;
        posY = rand()%(size-type);

        //Validate position
        while(!unique){
            for(int i = posY; i < posY + type; i++){
                if (map[posX][i] == 0){
                    unique = true;
                } else {
                    posX = rand()%size;
                    posY = rand()%(size-type);
                }
            }
        }

        //Position ship
        for(char y = posY; y < posY + type; y++)
            map[posX][y] = type;
    } else {
        //Vertical
        posX = rand()%(size-type);
        posY = rand()%size;

        //Validate position
        while(!unique){
            for(int i = posX; i < posX + type; i++){
                if (map[i][posY] == 0){
                    unique = true;
                } else {
                    posX = rand()%(size-type);
                    posY = rand()%size;
                }
            }
        }

        //Position ship
        for(char x = posX; x < posX + type; x++)
            map[x][posY] = type;
    }
}

void Computer::target(Coord &coord){
    
    //Initialize targets with random coordinates
    coord.x = rand()%size;
    coord.y = rand()%size;

    //Generate unique random X and Y targets
    for(int i = 0; i < pastX.size(); i++){
        if (coord.x == pastX[i] && coord.y == pastY[i]){
            i = 0;
            coord.x = rand()%size;
            coord.y = rand()%size;
        }
    }

    //Update past target vectors
    pastX.push_back(coord.x);
    pastY.push_back(coord.y);
}

bool Computer::turn(PlayerClass* enemy){
    bool win = false;
    string hit; //Hit indication
    Coord coord;
    target(coord); //Generate target coordinates
    cout << "The computer targets (" << static_cast<int>(coord.x+1) << ", " << static_cast<int>(coord.y+1) << ")." << endl;
    attack(*enemy, coord) ? hit = "Computer hits!" : hit = "Computer misses!"; //Attack generated target coordinates
    cout << hit << endl;
    //Test for player loss
    if (testEnd(*enemy)){
        win = true;
    }
    return win;
}
