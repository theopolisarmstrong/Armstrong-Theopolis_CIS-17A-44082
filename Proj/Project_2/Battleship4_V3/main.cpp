/*
 * File:   main.cpp
 * Author: Theopolis Armstrong
 * Created on April 14, 2019 12:30 pM
 * Purpose: Project 2 - Battleship 4 V1
 *
 * Title raw ASCII art generated using http://www.patorjk.com/software/taag/
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <cstdlib>  //C standard library
#include <cstring>  //String functions
#include <cmath>    //Math functions
#include <fstream>  //File stream objects
#include <iomanip>  //I/O stream manipulation library
#include <string> //String objects
#include <vector>   //Vector STL library
using namespace std;

//User Libraries
#include "Battleship.h"

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Structures
struct Player{
    char name[NAMELEN];
    char** ships; //Dynamically allocated array of ship positions
    char health[SHIPNUM] = {PATROL, DESTROY, CARRIER}; //Array of ship health
};

//Function Prototypes

void destroy(char**, const char); //De-allocates two dimensional dynamic array

//Game functions
char menu(char& choice);    //Output menu and receives player's menu choice
Player* initShip(const char size); //Initialize player structure
string shipName(Mapping); //Return ship name as string
void copyMap(char**, char**, const char);
void map(char**, const char);   //Output map
void cpuMap(char**, const char, const Mapping type = PATROL);   //Generate computer player ship positions
void pMap(Player*, const char, const Mapping type = PATROL);
//void sunk(char health[]);     TODO: requires ship positions validation
void genTar(char& targetX, char& targetY, const char&);  //Generate unique random targets for computer player
bool attack(char, char, Player*, Player*);  //Player turn; pass opposing player's ship placements for comparison
bool testEnd(char**, const char&);  //Test game end condition
Winner turn(Player*, Player*, const char, bool&);

//void saveProg(const Player*, const Player*); //Save game progress to file
//Options loadProg(Player*, Player*); //Initialize game w/ data from file
//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    Battleship game;
    
    //Initialize game
    game.init();
    
    //Gameplay loop
    game.loop();
    
    //Exit stage right or left!
    cout << endl << players[winner]->name << " wins!\n";
    //De-allocate players' structures
    for (char i = 0; i < PLAYNUM; i++){
        delete players[i];
    }
    return 0;
}

void destroy(char** array, const char size){
    for (char i = 0; i < size; i++){
        delete array[i];
    }
    delete array;
}

void map(char** ships, const char size){
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
            if (ships[row][col] == -2)
                cout << 'X';
            else if (ships[row][col] == -1)
                cout << 'O';
            else if (ships[row][col] == 1)
                cout << 'P';
            else if (ships[row][col] == 2)
                cout << 'D';
            else if (ships[row][col] == 3)
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

string shipName(Mapping ship){
    switch(ship){
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
            return "";
            break;
    }
}

void copyMap(char** array, char** copy, const char size){
    char** temp = new char*[size];
    for (int i = 0; i < size; i++){
        temp[i] = new char[size];
    }
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            copy[i][j] = array[i][j];
        }
    }
}

void cpuMap(char** ships, const char size, Mapping type){
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
                if (ships[posX][i] == 0){
                    unique = true;
                } else {
                    posX = rand()%size;
                    posY = rand()%(size-type);
                }
            }
        }
        
        //Position ship
        for(char y = posY; y < posY + type; y++)
            ships[posX][y] = type;
    } else {
        //Vertical
        posX = rand()%(size-type);
        posY = rand()%size;
        
        //Validate position
        while(!unique){
            for(int i = posX; i < posX + type; i++){
                if (ships[i][posY] == 0){
                    unique = true;
                } else {
                    posX = rand()%(size-type);
                    posY = rand()%size;
                }
            }
        }
        
        //Position ship
        for(char x = posX; x < posX + type; x++)
            ships[x][posY] = type;
    }
}

void pMap(Player* p, const char size, Mapping type){
    bool repos; //positioning loop flag
    char answer;    //positioning loop prompt input
    char orient = 'v';  //ship orientation
    char posX;  //Starting X-axis position of each ship
    char posY;  //Starting Y-axis position of each ship
    
    //Create temporary ship position 2D array
    char** temp = new char*[size];
    for (char i = 0; i < size; i++)
        temp[i] = new char[size];    copyMap(p->ships, temp, size);
    
    //Begin positioning ship
    cout << endl << p->name << ", position your " << shipName(type) << ": \n";
    do{
        map(temp, size);
        
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
                posX -= CHARNUM; //Convert ASCII code to integer
                maxVal(posX, size, "Error: Invalid x-axis (ensure the ship would not protrude outside the map)\nEnter a new x-axis value: ");
                cin >> posY;
                posY -= CHARNUM; //Convert ASCII code to integer
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
                posX -= CHARNUM; //Convert ASCII code to integer
                maxVal(posX, size - (type - 1), "Error: Invalid x-axis (ensure the ship would not protrude outside the map)\nEnter a new x-axis value: ");
                cin >> posY;
                posY -= CHARNUM; //Convert ASCII code to integer
                maxVal(posY, size, "Error: Invalid y-axis (ensure the ship would not protrude outside the map)\nEnter a new y-axis value: ");
                
                //Position ship
                for(char col = posX; col < posX + type; col++){
                    temp[posY - 1][col - 1] = type;
                }
                break;
            }
        }
        cout << "Your ships: \n";
        map(temp, size);
        
        //Prompt for repositioning
        repos = false;
        cout << "Would you like to reposition your ship [N/y]? ";
        cin >> answer;
        valid(answer, 'y', 'n', 'Y', 'N', "Error: Invalid answer");
        if (answer == 'y' || answer == 'Y'){
            repos = true;
            //Re-initialize temporary ship position array with current ship positions
            copyMap(p->ships, temp, size);
        }
    }while(repos);
    copyMap(temp, p->ships, size);
    destroy(temp, size);
}

void genTar(char& targetX, char& targetY, const char &size){
    static vector<char> pastX;  //Previous X-axis targets
    static vector<char> pastY;  //Previous Y-axis targets
    
    //Initialize targets with random coordinates
    targetX = rand()%size+1;
    targetY = rand()%size+1;
    
    //Generate unique random X and Y targets
    for(int i = 0; i < pastX.size(); i++){
        if (targetX == pastX[i] && targetY == pastY[i]){
            i = 0;
            targetX = rand()%size+1;
            targetY = rand()%size+1;
        }
    }
    //Update past target vectors
    pastX.push_back(targetX);
    pastY.push_back(targetY);
}

bool attack(char targetX, char targetY, Player* target, Player* p){
    targetX -= 1;
    targetY -= 1;
    if (target->ships[targetY][targetX] > 0){   //Ship is present
        //Modify ship health
        switch(target->ships[targetY][targetX]){
            case CARRIER:
                target->health[CARRIER-1] -= 1;
                break;
            case DESTROY:
                target->health[DESTROY-1] -= 1;
                break;
            case PATROL:
                target->health[PATROL-1] -= 1;
                break;
        }
        //Indicate ship hit on map
        target->ships[targetY][targetX] = HIT;        //Notify ship hit
        return true;
    } else if (target->ships[targetY][targetX] == 0){   //Ship is not present
        target->ships[targetY][targetX] = MISS;
        return false;
    } else if (target->ships[targetY][targetX] == -1 || target->ships[targetY][targetX] == -2){ //Target coordinates previously targeted
        return false;
    } else return false;
}

bool testEnd(char** ships, const char &size){
    bool end = true;    //End gameplay loop flag
    for (int row = 0; row < size; row++){
        for (int col = 0; col < size; col++){
            if (ships[row][col] > 0)
                end = false;
        }
    }
    return end;
}

Winner turn(Player* target, Player* p, const char size, bool &end){
    Winner win;
    char targetX, targetY;
    string hit; //Indicate a hit or miss
    float health = 0.0f; //Overall ship health percentage
    
    cout << "\n" << p->name << "'s turn: \n";
    //Get and validate target coordinates
    cout << "Enter a target coordinates: ";
    cin >> targetX;
    targetX -= CHARNUM;
    //    if(targetX == SAVE || targetX == SAVE_S){
    //        saveProg(target, p);
    //    }
    maxVal(targetX, size, "Error: Target x-axis out of range.\n"); //Validate target x coordinate
    cin >> targetY;
    targetY -= CHARNUM;
    //    if(targetX == SAVE || targetX == SAVE_S){
    //        saveProg(target, p);
    //    }
    maxVal(targetY, size, "Error: Target y-axis out of range.\n");  //Validate target y coordinate
    attack(targetX, targetY, target, p) ? hit = "Hit!" : hit = "Miss!"; //Check for and calculate hit or miss
    map(p->ships, size);
    cout << hit << endl;
    //Calculate and display health
    cout << "Health: ";
    health = 0.0f;
    for (char i : p->health){
        cout << static_cast<int>(i) << ' ';
        health += i;
    }
    cout << setprecision(2) << fixed;
    cout << "\nTotal health: " << (health / 6) * 100 << '%' << endl;
    
    //Test for computer loss
    if (testEnd(target->ships, size)){
        end = true;
        win = P1_WIN;
    } else win = NO_WIN;
    return win;
}

void chart(vector<char> turns){
    for (char i : turns){
        switch(i){
            case MISS:
                cout << "O ";
                break;
            case HIT:
                cout << "X ";
                break;
        }
    }
    cout << endl;
}

void save(const Player* p1){
    fstream file(S_FILE, ios::out | ios::binary);
    file.write(reinterpret_cast<const char*>(&p1->name), NAMELEN);
    file.write(reinterpret_cast<const char*>(&p1->health), SHIPNUM);
}
void load(){
    fstream file(S_FILE, ios::in | ios::binary);
    char name[NAMELEN], health[SHIPNUM], total = 0;
    
    if(!file){ //Ensure file opened correctly
        cout << "Error loading file";
    } else {
        file.read(reinterpret_cast<char*>(&name), NAMELEN);
        file.read(reinterpret_cast<char*>(&health), SHIPNUM);
        
        //Calculate health total
        for (char i = 0; i < SHIPNUM; i++)
            total+=health[i];
        
        cout << name << " won the game with " << static_cast<int>(total) << " health remaining!\n";
    }
}

//Quick init testing values
//1 4 v 2 1 n h 4 3 n v 1 1 n 1 1 n
