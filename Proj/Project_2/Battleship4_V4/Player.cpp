/*
 * File:   Player.cpp
 * Author: Theopolis Armstrong
 * Created on May 29, 2019 4:29 AM
 * Purpose: Human Player class definition
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdint>

using namespace std;
#include "Player.h"
#include "Input.h"

Player::Player(Player& orig) : PlayerClass(orig.name){
//    strlcpy(name, orig.name, NAMELEN);
    size = orig.size;
    initMap();
    copyMap(orig);
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
    
    //Display player's current map
    cout << "Player 1 map: \n";
    temp.showMap();
    
    //Begin positioning ship
    cout << endl << name << ", position your " << shipName(type) << ": \n";
    do{
        //Determine orientation of the ship
        if (type != PATROL){
            cout << "Is your ship vertical or horizontal [V/h]? ";
            read(orient);
            valid(orient, 'v', 'h', 'V', 'H', "Error: Invalid orientation");
        }
        
        //Position the ship in the correct orientation
        switch(orient){
            case 'v':
            case 'V':{
                //Input ship position
                cout << "Enter the top-most coordinates of the ship (ex. '5 3'): ";
                read(posX);
                posX = atoi(reinterpret_cast<char*>(&posX)); //Convert ASCII code to integer
                maxVal(posX, size, "Error: Invalid x-axis (ensure the ship would not protrude outside the map)\nEnter a new x-axis value: ");
                read(posY);
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
                read(posX);
                posX = atoi(reinterpret_cast<char*>(&posX)); //Convert ASCII code to integer
                maxVal(posX, size - (type - 1), "Error: Invalid x-axis (ensure the ship would not protrude outside the map)\nEnter a new x-axis value: ");
                read(posY);
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
        read(answer);
        valid(answer, 'y', 'n', 'Y', 'N', "Error: Invalid answer");
        if (answer == 'y' || answer == 'Y'){
            repos = true;
            //Re-initialize temporary ship position array with current ship positions
            temp.copyMap(*this);
        }
    }while(repos);
    copyMap(temp);
}

void Player::copyMap(PlayerClass& orig){
    size = orig.getSize();
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
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

bool Player::turn(PlayerClass* enemy){
    Coord coord;
    string hit; //Indicate a hit or miss
    float healthPerc = 0.0f; //Overall ship health percentage
    
    //Get and validate target coordinates
    showMap();
    cout << "Enter a target coordinates: ";
    read(coord.x);
    coord.x = atoi(reinterpret_cast<char*>(&coord.x));
    maxVal(coord.x, size, "Error: Target x-axis out of range.\nEnter a new value: "); //Validate target x coordinate
    read(coord.y);
    coord.y -= 48;
    maxVal(coord.y, size, "Error: Target y-axis out of range.\nEnter a new value: ");  //Validate target y coordinate
    coord.x -= 1;
    coord.y -= 1;
    attack(*enemy, coord) ? hit = "hit" : hit = "missed"; //Check for and calculate hit or miss
    cout << endl << "You " << hit << ' ' << enemy << "'s ships!\n";
    //Calculate and display health
    healthPerc = 0.0f;
    for (char i : health){
        healthPerc += i;
    }
    cout << setprecision(2) << fixed;
    cout << "Total health: " << (healthPerc / 6) * 100 << '%' << endl;
    
    //Test for computer loss
    if (testEnd(*enemy))
        return true;
    return false;
}
