/*
 * File:   Player.cpp
 * Author: Theopolis Armstrong
 * Created on May 29, 2019 4:29 AM
 * Purpose: Human Player class definition
 */


#include "Input.h"
#include "Player.h"
using namespace std;

Player::Player(const Player& orig) : PlayerClass(orig.size){
    strcpy(name, orig.name);
    //Copy map
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; i++){
            map[i][j] = orig.map[i][j];
        }
    }
}

void Player::place(Mapping type){
    bool repos; //positioning loop flag
    char answer;    //positioning loop prompt input
    char orient = 'v';  //ship orientation
    uint8_t posX;  //Starting X-axis position of each ship
    uint8_t posY;  //Starting Y-axis position of each ship
    
    //Create temporary ship position 2D array
    Player temp(*this);
    temp.setName("temp");
    
    //Begin positioning ship
    cout << endl << name << ", position your " << shipName(type) << ": \n";
    do{
        
        
        //Determine orientation of the ship
        if (type != PATROL){
            cout << "Is your ship vertical or horizontal [V/h]? ";
            cin >> orient;
            valid(orient, 'v', 'h', 'V', 'H', "Error: Invalid orientation");
        }
        
        //Position the ship in the correct orientation
        switch(orient){
            case 'v':
            case 'V':{
                //Input ship position
                cout << "Enter the top-most coordinates of the ship (ex. '5 3'): ";
                cin >> posX;
                posX = atoi(reinterpret_cast<char*>(&posX)); //Convert ASCII code to integer
                maxVal(posX, size, "Error: Invalid x-axis (ensure the ship would not protrude outside the map)\nEnter a new x-axis value: ");
                cin >> posY;
                posY = atoi(reinterpret_cast<char*>(&posY)); //Convert ASCII code to integer
                maxVal(posY, size - (type - 1), "Error: Invalid y-axis (ensure the ship would not protrude outside the map)\nEnter a new y-axis value: ");
                
                //Position ship
                for(char row = posY; row < posY + type; row++){
                    temp[row - 1][posX - 1] = type;
                }
                break;
            }
            case 'h':
            case 'H':{
                //Input ship position
                cout << "Enter the top-most coordinates of the ship (ex. '3 1'): ";
                cin >> posX;
                posX = atoi(reinterpret_cast<char*>(&posX)); //Convert ASCII code to integer
                maxVal(posX, size - (type - 1), "Error: Invalid x-axis (ensure the ship would not protrude outside the map)\nEnter a new x-axis value: ");
                cin >> posY;
                posY = atoi(reinterpret_cast<char*>(&posY)); //Convert ASCII code to integer
                maxVal(posY, size, "Error: Invalid y-axis (ensure the ship would not protrude outside the map)\nEnter a new y-axis value: ");
                
                //Position ship
                for(char col = posX; col < posX + type; col++){
                    temp[posY - 1][col - 1] = type;
                }
                break;
            }
        }
        cout << "Your ships: \n";
        temp.showMap();
        
        //Prompt for repositioning
        repos = false;
        cout << "Would you like to reposition your ship [N/y]? ";
        cin >> answer;
        valid(answer, 'y', 'n', 'Y', 'N', "Error: Invalid answer");
        if (answer == 'y' || answer == 'Y'){
            repos = true;
            //Re-initialize temporary ship position array with current ship positions
            temp.copyMap(this->map);
        }
    }while(repos);
    copyMap(temp.map);
}

void Player::copyMap(int8_t** orig){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; i++){
            map[i][j] = orig[i][j];
        }
    }
}
string Player::shipName(Mapping shipType){
    switch(shipType){
        case CARRIER:
            return "Carrier";
            break;
        case DESTROY:
            return "Destroyer";
            break;
        case PATROL:
            return "Patrol";
            break;
        default:
            return "[No ship type found]";
            break;
    }
}
