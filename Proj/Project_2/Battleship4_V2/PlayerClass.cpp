/*
 * File:   PlayerClass.cpp
 * Author: Theopolis Armstrong
 * Created on May 29, 2019 3:10 AM
 * Purpose: Virtual Player class definition
 */

#include "PlayerClass.h"
using namespace std;

const uint8_t PlayerClass::NAMELEN = 9;

PlayerClass::PlayerClass(const uint8_t size){
    initMap();
}
PlayerClass::PlayerClass(const uint8_t size, const char n[]){
    strlcpy(name, n, NAMELEN); //Set name
    initMap(); //Initialize map
}
PlayerClass::~PlayerClass(){
    for (char i = 0; i < size; i++){
        delete map[i];
    }
    delete map;
}

void PlayerClass::initMap(){
    //Dynamically allocate two dimensional grid
    map = new uint8_t*[size];
    for (int i = 0; i < size; i++){
        map[i] = new uint8_t[size];
    }
    //Initialize map with 0's
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            map[i][j] = 0;
        }
    }
}
