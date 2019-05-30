/*
 * File:   PlayerClass.cpp
 * Author: Theopolis Armstrong
 * Created on May 29, 2019 3:10 AM
 * Purpose: Virtual Player class definition
 */

#include "PlayerClass.h"
using namespace std;

const uint8_t PlayerClass::NAMELEN = 9;

//TODO
//Memory allocation exception handling
//
PlayerClass::PlayerClass(const uint8_t s) : size(s) {
    initMap();
}
//TODO
//Memory allocation exception handling
//
PlayerClass::PlayerClass(const uint8_t s, const char n[]) : size(s) {
    strlcpy(name, n, NAMELEN); //Set name
    initMap(); //Initialize map
}
PlayerClass::~PlayerClass(){
    //Deallocate 2D map array
    for (char i = 0; i < size; i++){
        delete map[i];
    }
    delete map;
}

//TODO
//Memory allocation exception handling
//
void PlayerClass::initMap(){
    //Dynamically allocate two dimensional grid
    map = new int8_t*[size];
    for (int i = 0; i < size; i++){
        map[i] = new int8_t[size];
    }
    //Initialize map with 0's
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            map[i][j] = 0;
        }
    }
}
void PlayerClass::showMap() const {
    //Output column headers and top divider
    cout << "     ";
    for (char i = 0; i < size * 6; i++){ //iterate though each space in the map output; map size * 6 characters per cell - 3 header characters
        if (i % 6 == 0)
            cout << i / 6 + 1;
        else
            cout << ' ';
    }
    cout << endl << "   ";
    for (char i = 0; i < size * 6 - 1; i++){
        cout << '-';
    }
    cout << endl;
    
    //Output table body and row headers
    for(char row = 0; row < size; row++){
        //Padding row
        cout << "  |";
        for (int i = 0; i < size; i++){
            cout << "     |";
        }
        cout << endl;
        
        //Data row
        cout << row + 1 << " |  ";
        for(char col = 0; col < size; col++){
            if (map[row][col] == -2)
                cout << 'X';
            else if (map[row][col] == -1)
                cout << 'O';
            else if (map[row][col] == 1)
                cout << 'P';
            else if (map[row][col] == 2)
                cout << 'D';
            else if (map[row][col] == 3)
                cout << 'C';
            else cout << ' ';
            cout << "  |  ";
        }
        cout << endl;
        
        //Padding row
        cout << "  |";
        for (int i = 0; i < size; i++)
            cout << "     |";
        cout << endl;
        
        //Dividing row
        cout << "   ";
        for (char i = 0; i < size * 6 - 1; i++){
            cout << '-';
        }
        cout << endl;
    }
    cout << "C = Aircraft Carrier (3 spaces), D = Destroyer (2 spaces), P = Patrol Boat (1 space), X = Hit\n";
}

//Overloaded Operators
int8_t* PlayerClass::operator[](const int &i){
    if(i >= 0 && i < size) return map[i];
    else return 0;
}
