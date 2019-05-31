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
        char unique = false;
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
    static vector<char> pastX;  //Previous X-axis targets
    static vector<char> pastY;  //Previous Y-axis targets

    //Initialize targets with random coordinates
//    Coord coord = {
//        static_cast<uint8_t>(rand()%size+1),
//        static_cast<uint8_t>(rand()%size+1)};
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
    cout << "Past X: ";
    for (auto i : pastX) cout << static_cast<int>(i+1) << ' ';
    cout << "\nPast Y: ";
    for (auto i : pastY) cout << static_cast<int>(i+1) << ' ';
    cout << endl;
}

bool Computer::attack(PlayerClass& enemy, const Coord& target){
    //Adjust target input for 2D array index
//    Coord target {static_cast<uint8_t>(coord.x-1), static_cast<uint8_t>(coord.y-1)};
//    Coord target;
    //Find target space status
    if (enemy[target.y][target.x] > 0){   //Ship is present
        //Modify ship health
        switch(enemy[target.y][target.x]){
            case CARRIER:
                enemy.setHealth(CARRIER-1, enemy.getHealth(CARRIER)-1);
                break;
            case DESTROY:
                enemy.setHealth(DESTROY-1, enemy.getHealth(DESTROY)-1);
                break;
            case PATROL:
                enemy.setHealth(PATROL-1, enemy.getHealth(PATROL)-1);
                break;
        }
        //Indicate ship hit on map
        enemy[target.y][target.x] = HIT;        //Notify ship hit
        return true;
    } else if (enemy[target.y][target.x] == 0){   //Ship is not present
        enemy[target.y][target.x] = MISS;
        return false;
    } else if (enemy[target.y][target.x] == -1 || enemy[target.y][target.x] == -2){ //Target coordinates previously targeted
        return false;
    } else return false;
}

bool Computer::turn(PlayerClass* enemy){
    bool win = false;
    Coord coord;
    target(coord); //Generate target coordinates
    string hit; //Hit indication
    cout << "The computer targets (" << static_cast<int>(coord.x+1) << ", " << static_cast<int>(coord.y+1) << ")." << endl;
    attack(*enemy, coord) ? hit = "Computer hits!" : hit = "Computer misses!"; //Attack generated target coordinates
    cout << hit << endl;
    //Test for player loss
    if (testEnd(*enemy)){
        win = true;
    }
    return win;
}
