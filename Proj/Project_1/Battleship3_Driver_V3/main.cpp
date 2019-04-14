/*
 * File:   main.cpp
 * Author: Theopolis Armstrong
 * Created on April 13, 2019
 * Purpose: Project 1 - Battleship 3
 *
 * Title raw ASCII art generated using http://www.patorjk.com/software/taag/
 *
 * Working representation of progress at Battleship 3 V3 main file
 *  Completed player vs computer initialization/structure integration
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <cstdlib>  //C standard library
#include <cstring>  //String functions
#include <cmath>    //Math functions
#include <fstream>  //File stream objects
#include <iomanip>  //I/O stream manipulation library
#include <vector>   //Vector STL library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...
const unsigned char CHARNUM = 48;   //Char constant to integer constant conversion
const unsigned char SHIPNUM = 3; //Number of available ship types
const unsigned char NAMELEN = 9; //Length of player name

//Enumerators
enum Mapping {HIT = -2, MISS = -1, PATROL = 1, DESTROY, CARRIER};

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
bool valShip(char** ships, const char type, const char orient, const char posX, const char posY); //Validate ship position
void maxVal(char& input, const char maxVal, const string error);

void bubble(vector<char>& a); //Bubble sort a vector
void select(vector<char>& a); //Selection sort a vector

void destroy(char**, const char); //De-allocates two dimensional dynamic array

//Game functions
void title();   //Output title header
char menu(char& choice);    //Output menu and receives player's menu choice
Player* initShip(const char size);
void copyMap(char**, char**, const char);
void map(char**, const char);   //Output map
void cpuMap(char**, const char, const unsigned char type = 1);   //Generate computer player ship positions
void pMap(Player*, const char, const unsigned char type = 1);
//void sunk(char health[]);     requires ship positions validation
void genTar(char& targetX, char& targetY);  //Generate unique random targets for computer player
void updateV(char x, char y, vector<char>& pastX, vector<char>& pastY);
void chart(vector<char> health);    //chart hit and miss vector
void saveProg(fstream &); //Save game progress to file
void loadProg(const fstream &); //Initialize game w/ data from file
void saveWin(string file, string winner, vector<char> turns);   //save win stats to file
void loadWin(string file); //load win stats from file

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    enum Mode {NONE, PVCPU, PVP, EXIT = 9};
    enum Winner {CPU, P1, P2};
    enum PlayInd {PI1, PI2}; //Index of player
    const char PLAYNUM = 2; //Number of players
    const string WIN = "win.dat";
    const string SAVE = "save.dat";
    
    Player* players[PLAYNUM];
    
    Mode gameMode = NONE; //game mode chosen in menu
    Winner winner; //winner of the game
    bool end = false; //end game flag
    char choice; //menu choice
    short size; //Map size
    
    char targetX, targetY;  //Target coordinates
    
    string hit;   //Indicates a hit
    string winName; //Name of the winner
    
    //Initialize game
    title();
    while(!gameMode){   //Loop menu until game mode is chosen
        switch(menu(choice)){
            case PVCPU:
                cout << "Initializing Player vs. Computer game mode.\nEnter a 0 at any time to quit.\n";
                cout << "Enter map size: ";
                cin >> size;
                gameMode = PVCPU; //Set game mode
                players[PI1] = initShip(size);
                players[PI2] = initShip(size);
                strcpy(players[PI1]->name, "Player 1");
                strcpy(players[PI2]->name, "Computer");
                
                cout << "Setting CPU ship placements...\n";
                //Place computer player ships
                cpuMap(players[PI2]->ships, size, CARRIER);
                cpuMap(players[PI2]->ships, size, DESTROY);
                cpuMap(players[PI2]->ships, size);
                map(players[PI2]->ships, size);
                //Input and set player ships
                cout << "Place you Aircraft Carrier.\n";
                pMap(players[PI1], size, CARRIER);
                cout << "Place you Destroyer.\n";
                pMap(players[PI1], size, DESTROY);
                cout << "Place you Patrol Boat.\n";
                pMap(players[PI1], size, PATROL);
                cout << endl;
            case 9:
                cout << "Goodbye.\n";
                return 0;
                break;
        }
    }
    
    //Exit stage right or left!
    return 0;
}

//Validation
void maxVal(char& input, const char maxVal, const string error){
    if (input == 9 || input == '9'){
        cout << "Goodbye!\n";
        exit(0);
    }
    while (input > maxVal && input != 9){
        cout << error << endl;
        cin >> input;
        input -= CHARNUM;
    }
}
void valid(char& input, const char val1, const char val2, const string error){
    if (input == 9 || input == '9'){
        cout << "Goodbye!\n";
        exit(0);
    }
    while (input != val1 && input != val2 && input != 9){
        cout << error << endl;
        cin >> input;
    }
}
void valid(char& input, const char val1, const char val2, const char val3, const string error){
    if (input == 9 || input == '9'){
        cout << "Goodbye!\n";
        exit(0);
    }
    while (input != val1 && input != val2 && input != val3 && input != 9){
        cout << error << endl;
        cin >> input;
    }
}
void valid(char& input, const char val1, const char val2, const char val3, const char val4, const string error){
    if (input == 9 || input == '9'){
        cout << "Goodbye!\n";
        exit(0);
    }
    while (input != val1 && input != val2 && input != val3 && input != val4 && input != 9){
        cout << error << endl;
        cin >> input;
    }
}
bool valShip(char** ships, const char type, const char orient, const char posX, const char posY){
    for(int i = posX; i < posX + type; i++){
        if (ships[i][posY]) return false;
    }
    return true;
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
    cout << "4. Display last winner\n";
    cout << "9. Exit\n";
    
    cin >> choice;
    choice -= CHARNUM; //convert ascii code to integer
    while (choice != 1 && choice != 2 && choice != 3 && choice != 0){
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

void cpuMap(char** ships, const char size, const unsigned char type){
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

void pMap(Player* p, const char size, const unsigned char type){
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
    cout << endl << p->name << ", position your ship: \n";
    do{
        map(temp, size);
        
        //Determine orientation of the ship
        if (type != PATROL){
            cout << "Is your ship vertical or horizontal [V/h]? ";
            cin >> orient;
            cout << "orient: " << orient <<endl;
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
                cout << "Limit: " << size - (type - 1) << endl;
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
            destroy(temp, size);
            copyMap(p->ships, temp, size);
        }
    }while(repos);
    copyMap(temp, p->ships, size);
    destroy(temp, size);
}
