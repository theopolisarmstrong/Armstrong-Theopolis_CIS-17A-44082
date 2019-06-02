/*
 * File:   PlayerClass.cpp
 * Author: Theopolis Armstrong
 * Created on May 29, 2019 3:10 AM
 * Purpose: Virtual Player class definition
 */

#include <iostream>
#include <cstring>

#include "PlayerClass.h"
using namespace std;

const uint8_t PlayerClass::SHIPNUM = 3;
const uint8_t PlayerClass::MAPMIN = 4;

//Constructors

//Deconstructor
PlayerClass::~PlayerClass(){
    //Deallocate 2D map array
    if (size > 0){
        for (char i = 0; i < size; i++){
            delete [] map[i];
        }
        delete [] map;
    }
}

//Mutators

//Accessors

//Internal player functins
void PlayerClass::initMap(){
    //Dynamically allocate two dimensional grid
    try{
        map = new int8_t*[size];
    }
    catch (bad_alloc){
        cout << "Error: Memory allocation failure.\n";
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < size; i++){
        try{
            map[i] = new int8_t[size];
        }
        catch (bad_alloc){
            cout << "Error: Memory allocation failure.\n";
            exit(EXIT_FAILURE);
        }
    }
    //Initialize map with 0's
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            map[i][j] = 0;
        }
    }
}
bool PlayerClass::attack(PlayerClass& enemy, const Coord& target){
    //Adjust target input for 2D array index
    //Find target space status
    if (target.x < size && target.y < size){
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
    } else return false;
}
bool PlayerClass::testEnd(PlayerClass& p) const {
    bool end = true; //End gameplay loop flag
    for (int row = 0; row < size; row++){
        for (int col = 0; col < size; col++){
            if ( p[row][col] > 0)
                end = false;
        }
    }
    return end;
}

//Player functions
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
    cout << "C = Aircraft Carrier (3 spaces), D = Destroyer (2 spaces), P = Patrol Boat (1 space), X = Hit, O = Miss\n";
}
void PlayerClass::debugMap() const {
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            cout << static_cast<int>(map[i][j]) << ' ';
        }
        cout << endl;
    }
}

//Overloaded Operators
int8_t* PlayerClass::operator[](const int &i){
    if(i >= 0 && i < size) return map[i];
    else return 0;
}
bool PlayerClass::operator>(const PlayerClass &right){
    if (health > right.health)
        return true;
    return false;
}
bool PlayerClass::operator<(const PlayerClass &right){
    if (health < right.health)
        return true;
    return false;
}
ostream& operator<<(ostream& strm, const class PlayerClass* obj){
    strm << obj->name;
    return strm;
}
istream& operator>>(istream& strm, class PlayerClass* obj){
    strm >> obj->name;
    return strm;
}
