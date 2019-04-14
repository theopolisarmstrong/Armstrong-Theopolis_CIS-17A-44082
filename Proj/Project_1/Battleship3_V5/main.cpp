/*
 * File:   main.cpp
 * Author: Theopolis Armstrong
 * Created on April 14, 2019 8:54 AM
 * Purpose: Project 1 - Battleship 3 V5
 *
 * Title raw ASCII art generated using http://www.patorjk.com/software/taag/
 *
 * Working representation of progress at Battleship 3 V3 main file
 *  Completed player vs computer initialization/structure integration
 *  Completed player vs player initialization/structure integration
 *  Completed player vs computer gameplay loop
 *  Completed player vs player gameplay loop
 *  WIP Saving, loading,
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

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...
const unsigned char CHARNUM = 48;   //Char constant to integer constant conversion
const unsigned char SHIPNUM = 3; //Number of available ship types
const unsigned char NAMELEN = 9; //Length of player name
const string S_FILE = "save.dat"; //Save file name

//Enumerators
enum Mapping {HIT = -2, MISS = -1, PATROL = 1, DESTROY, CARRIER}; //Map indications/ship size
enum Options {NONE = 0, PVCPU, PVP, LOAD, SAVE = (static_cast<int>('s')-CHARNUM), SAVE_S = (static_cast<int>('S')-CHARNUM), EXIT = (static_cast<int>('e')-CHARNUM), EXIT_E = (static_cast<int>('E')-CHARNUM)}; //Menu choice options/game modes
enum Winner {NO_WIN = -1, P1_WIN, P2_WIN, CPU_WIN = 1}; //Winner of the game

//Structures
struct Player{
    char name[NAMELEN];
    char** ships; //Dynamically allocated array of ship positions
    char health[SHIPNUM] = {PATROL, DESTROY, CARRIER}; //Array of ship health
    vector<char> turns; //Hit status per turn
    float percent = 0.0f; //Hit percentage
};

//Function Prototypes
//Validation inputs and overloads; exit if input is 0
void valid(char&, const char, const char, const string);
void valid(char&, const char, const char, const char, const string);
void valid(char&, const char, const char, const char, const char, const string);
void maxVal(char&, const char, const string); //Ensures input is below max value
void minVal(char&, const char, const string); //Ensures input is above min value

void destroy(char**, const char); //De-allocates two dimensional dynamic array

//Game functions
void title();   //Output title header
char menu(char& choice);    //Output menu and receives player's menu choice
Player* initShip(const char size);
string shipName(Mapping); //Return ship name as string
void copyMap(char**, char**, const char);
void map(char**, const char);   //Output map
void cpuMap(char**, const char, const Mapping type = PATROL);   //Generate computer player ship positions
void pMap(Player*, const char, const Mapping type = PATROL);
//void sunk(char health[]);     TODO: requires ship positions validation
void genTar(char& targetX, char& targetY, const char&);  //Generate unique random targets for computer player
void updateV(const char &x, const char &y, vector<char>& pastX, vector<char>& pastY);
bool attack(char, char, Player*, Player*);  //Player turn; pass opposing player's ship placements for comparison
bool testEnd(char**, const char&);  //Test game end condition
Winner turn(Player*, Player*, const char, bool&);
void chart(vector<char> health);    //chart hit and miss vector
void saveProg(const Player*, const Player*); //Save game progress to file
void loadProg(Player*, Player*); //Initialize game w/ data from file
//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    enum PlayInd {P1, P2, CPU = 1}; //Index of player
    const char PLAYNUM = 2; //Number of players
    
    Player* players[PLAYNUM];
    
    Options gameMode = NONE; //game mode chosen in menu
    Winner winner = NO_WIN; //winner of the game
    bool end = false; //end game flag
    char choice; //menu choice
    char size = 0; //Map size
    char targetX, targetY;  //Target coordinates
    string hit;   //Indicates a hit
    
    //Initialize game
    title();
    while(gameMode == NONE){   //Loop menu until game mode is chosen
        switch(menu(choice)){
            case PVCPU:
                //Initialize game
                cout << "Initializing Player vs. Computer game mode.\nEnter " << static_cast<char>(EXIT_E+CHARNUM) << " at any time to quit.\n";
                cout << "Enter map size: ";
                cin >> size;
                size -= CHARNUM;
                minVal(size, 4, "Error: Size too low.\n");
                gameMode = PVCPU; //Set game mode
                //Initialize player structures
                players[P1] = initShip(size);
                players[CPU] = initShip(size);
                strlcpy(players[P1]->name, "Player 1", NAMELEN);
                strlcpy(players[CPU]->name, "Computer", NAMELEN);
                
                //Set ship positions
                cout << "Setting CPU ship placements...\n";
                //Place computer player ships
                cpuMap(players[CPU]->ships, size, CARRIER);
                cpuMap(players[CPU]->ships, size, DESTROY);
                cpuMap(players[CPU]->ships, size);
                //                map(players[CPU]->ships, size); //Map cpu ship placements for debugging
                //Input and set player ships
                pMap(players[P1], size, CARRIER);
                pMap(players[P1], size, DESTROY);
                pMap(players[P1], size, PATROL);
                cout << endl;
                break;
            case PVP:
                //Initialize game
                cout << "Initializing Player vs. Player game mode.\nEnter a 0 at any time to quit.\n";
                cout << "Enter map size: ";
                cin >> size;
                size -= CHARNUM;
                minVal(size, 4, "Error: Size too low.\n");
                gameMode = PVP; //Set game mode
                //Initialize player structures
                players[P1] = initShip(size);
                players[P2] = initShip(size);
                strlcpy(players[P1]->name, "Player 1", NAMELEN);
                strlcpy(players[P2]->name, "Player 2", NAMELEN);
                
                //Set ship positions
                pMap(players[P1], size, CARRIER);
                pMap(players[P1], size, DESTROY);
                pMap(players[P1], size);
                cout << endl;
                pMap(players[P2], size, CARRIER);
                pMap(players[P2], size, DESTROY);
                pMap(players[P2], size);
                cout << endl;
                break;
            case EXIT:
            case EXIT_E:
                cout << "Goodbye.\n";
                return 0;
                break;
        }
    }
    
    //Gameplay loop
    cout << "********\n" <<"*BEGIN!*\n" << "********\n\n";
    cout << "Enter " << static_cast<char>(EXIT_E+CHARNUM) << " at any time to quit.\n";
    cout << "Enter " << static_cast<char>(SAVE_S+CHARNUM) << " at any time to save and quit.\n";
    switch(gameMode){
            //Player vs. CPU
        case PVCPU:{
            while(!end){
                //Player turn
                winner = turn(players[CPU], players[P1], size, end);
                map(players[CPU]->ships, size); //Map CPU ships for debugging
                //Computer Turn
                if (!end){
                    cout << "\nComputer's turn: \n";
                    genTar(targetX, targetY, size);
                    cout << "The computer targets (" << static_cast<int>(targetX) << ", " << static_cast<int>(targetY) << ")." << endl;
                    attack(targetX, targetY, players[P1], players[CPU]) ? hit = "Computer hits!" : hit = "Computer misses!";  //Take computer's turn using random X and Y target coord's [1-size of map]
                    cout << hit << endl;
                    //Test for player loss
                    if (testEnd(players[P1]->ships, size)){
                        end = true;
                        winner = CPU_WIN;
                    }
                }
            }
            break;}
        case PVP:{
            while(!end){
                //Player 1's turn
                winner = turn(players[P2], players[P1], size, end);
                //Player 2 Turn
                if(!end){
                    winner = turn(players[P1], players[P2], size, end);
                }
            }
            break;}
    }
    
    //Exit stage right or left!
    cout << endl << players[winner]->name << " wins!\n";
    cout << "Hit ratio chart: \n";
    chart(players[winner]->turns);
    cout << endl;
    //De-allocate players' structures
    for (char i = 0; i < PLAYNUM; i++){
        delete players[i];
    }
    return 0;
}

//Validation
void maxVal(char& input, const char maxVal, const string error){
    if (input == EXIT || input == EXIT_E){
        cout << "Goodbye!\n";
        exit(0);
    }
    while (input > maxVal && input != EXIT && input != SAVE){
        cout << error << endl;
        cin >> input;
        input -= CHARNUM;
    }
}
void minVal(char& input, const char minVal, const string error){
    if (input == EXIT || input == EXIT_E){
        cout << "Goodbye!\n";
        exit(0);
    }
    while (input < minVal && input != EXIT && input != SAVE){
        cout << error << endl;
        cin >> input;
        input -= CHARNUM;
    }
}
void valid(char& input, const char val1, const char val2, const string error){
    if (input == EXIT || input == EXIT_E){
        cout << "Goodbye!\n";
        exit(0);
    }
    while (input != val1 && input != val2 && input != EXIT && input != SAVE){
        cout << error << endl;
        cin >> input;
    }
}
void valid(char& input, const char val1, const char val2, const char val3, const string error){
    if (input == EXIT || input == EXIT_E){
        cout << "Goodbye!\n";
        exit(0);
    }
    while (input != val1 && input != val2 && input != val3 && input != EXIT && input != SAVE){
        cout << error << endl;
        cin >> input;
    }
}
void valid(char& input, const char val1, const char val2, const char val3, const char val4, const string error){
    if (input == EXIT || input == EXIT_E){
        cout << "Goodbye!\n";
        exit(0);
    }
    while (input != val1 && input != val2 && input != val3 && input != val4 && input != EXIT && input != SAVE){
        cout << error << endl;
        cin >> input;
    }
}

void destroy(char** array, const char size){
    for (char i = 0; i < size; i++){
        delete array[i];
    }
    delete array;
}

void title(){
    cout << " ____        _   _   _           _     _" << endl;
    cout << "|  _ \\      | | | | | |         | |   (_)" << endl;
    cout << "| |_) | __ _| |_| |_| | ___  ___| |__  _ _ __" << endl;
    cout << "|  _ < / _` | __| __| |/ _ \\/ __| '_ \\| | '_ \\" << endl;
    cout << "| |_) | (_| | |_| |_| |  __/\\__ \\ | | | | |_) |" << endl;
    cout << "|____/ \\__,_|\\__|\\__|_|\\___||___/_| |_|_| .__/" << endl;
    cout << "                                      | |\n";
    cout << "                                      |_|\n";
}

char menu(char& choice){
    cout << "Choose a menu item: \n";
    cout << "1. Player vs. CPU\n";
    cout << "2. Player vs. Player\n";
    cout << "3. Load game from file\n";
    cout << "E. Exit\n";
    
    cin >> choice;
    choice -= CHARNUM; //convert ascii code to integer
    while (choice != PVCPU && choice != PVP && choice != LOAD && choice != SAVE && choice != EXIT){
        cout << "Error: Invalid menu choice\n";
        cin >> choice;
        choice -= CHARNUM; //convert ascii code to integer
    }
    return choice;
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

Player* initShip(const char size){
    Player* temp = new Player;
    //Dynamically allocate two dimensional array for ships
    temp->ships = new char*[size];
    for (int i = 0; i < size; i++){
        temp->ships[i] = new char[size];
    }
    //Initialize ships
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            temp->ships[i][j] = 0;
        }
    }
    return temp;
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

void updateV(const char &x, const char &y, vector<char>& pastX, vector<char>& pastY){
    pastX.push_back(x);
    pastY.push_back(y);
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
    updateV(targetX, targetY, pastX, pastY);
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
        target->ships[targetY][targetX] = HIT;
        p->turns.push_back(HIT);
        //Notify ship hit
        return true;
    } else if (target->ships[targetY][targetX] == 0){   //Ship is not present
        target->ships[targetY][targetX] = MISS;
        p->turns.push_back(MISS);
        return false;
    } else if (target->ships[targetY][targetX] == -1 || target->ships[targetY][targetX] == -2){ //Target coordinates previously targeted
        p->turns.push_back(MISS);
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
    if(targetX == SAVE || targetX == SAVE_S){
        saveProg(target, p);
    }
    maxVal(targetX, size, "Error: Target x-axis out of range.\n"); //Validate target x coordinate
    cin >> targetY;
    targetY -= CHARNUM;
    if(targetX == SAVE || targetX == SAVE_S){
        saveProg(target, p);
    }
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

void saveProg(const Player* p1, const Player* p2){
    fstream file(S_FILE, ios::out | ios::binary);
    cout << "Saving...\n";
    file.write(reinterpret_cast<const char*>(p1), sizeof(p1));
    file.write(reinterpret_cast<const char*>(p2), sizeof(p2));
    cout << "Progress saved.\n";
    file.close();
    cout << "Quiting.\n";
    exit(0);
}
void loadProg(Player* p1, Player* p2){
    
}

//Quick init testing values
//1 4 v 2 1 n h 4 3 n v 1 1 n 1 1 n
