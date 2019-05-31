/*
 * File:   Player.cpp
 * Author: Theopolis Armstrong
 * Created on May 29, 2019 4:29 AM
 * Purpose: Human Player class definition
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include "Player.h"
#include "Input.h"

Player::Player(Player& orig) : PlayerClass(){
    strcpy(name, orig.name);
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

bool Player::attack(PlayerClass& enemy, const Coord &target){
    
    return false;
}
bool Player::turn(PlayerClass* enemy){
    Coord coord;
    string hit; //Indicate a hit or miss
    float healthPerc = 0.0f; //Overall ship health percentage
    
    //Get and validate target coordinates
    cout << "Enter a target coordinates: ";
    cin >> coord.x;
    coord.x = atoi(reinterpret_cast<char*>(&coord.x));
    //    if(targetX == SAVE || targetX == SAVE_S){
    //        saveProg(target, p);
    //    }
    maxVal(coord.y, size, "Error: Target x-axis out of range.\n"); //Validate target x coordinate
    cin >> coord.y;
    coord.y = atoi(reinterpret_cast<char*>(&coord.y));
    //    if(targetX == SAVE || targetX == SAVE_S){
    //        saveProg(target, p);
    //    }
    maxVal(coord.y, size, "Error: Target y-axis out of range.\n");  //Validate target y coordinate
    attack(*enemy, coord) ? hit = "Hit!" : hit = "Miss!"; //Check for and calculate hit or miss
    showMap();
    cout << hit << endl;
    //Calculate and display health
    cout << "Health: ";
    healthPerc = 0.0f;
    for (char i : health){
        cout << static_cast<int>(i) << ' ';
        healthPerc += i;
    }
    cout << setprecision(2) << fixed;
    cout << "\nTotal health: " << (healthPerc / 6) * 100 << '%' << endl;
    
    //Test for computer loss
    if (testEnd(*enemy))
        return true;
    return false;
}
