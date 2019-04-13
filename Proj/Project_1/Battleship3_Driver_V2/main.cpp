/*
 * File:   main.cpp
 * Author: Theopolis Armstrong
 * Created on April 13, 2019
 * Purpose: Project 1 - Battleship 3
 *
 * Title raw ASCII art generated using http://www.patorjk.com/software/taag/
 *
 * Working representation of progress at Battleship 3 V2 main file
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

//Enumerators
enum Mapping {HIT = -2, MISS = -1, PATROL = 1, DESTROY, CARRIER};

//Structures
struct Player{
    char** ships; //Dynamically allocated array of ship positions
    char* health;
    vector<char> turns;
};

//Function Prototypes
//Validation inputs and overloads; exit if input is 0
bool valid(char& input, char val1, char val2, string error);
bool valid(char& input, char val1, char val2, char val3, string error);
bool valid(char& input, char val1, char val2, char val3, char val4, string error);
bool max(char& input, char maxVal, string error);

void bubble(vector<char>& a);
void select(vector<char>& a);

//Game functions
void title();   //Output title header
char menu(char& choice);    //Output menu and receives player's menu choice
char** initCPU(const char size);
void map(char**, const char);   //Output map
void cpuMap(char**, const char, Mapping ship = PATROL);   //Generate computer player ship positions
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
    const unsigned char PVCPU = 1; //player vs computer game mode flag
    const unsigned char PVP = 2;   //player vs player game mode flag
    
    const string WIN = "win.dat";
    const string SAVE = "save.dat";
    
    bool end = false;   //end game flag
    char winner = 0;    //winner of the game
    char gameMode = 0;  //game mode chosen in menu
    char choice;    //menu choice
    short size; //Map size
    
    Player* p1, p2, cpu;
    
    char targetX, targetY;  //Target coordinates
    
    string hit;   //Indicates a hit
    string winName; //Name of the winner
    float health = 0.0f;   //hit percentage of player 1, player 2, and CPU
    
    //Initialize game
    title();
    while(!gameMode){   //Loop menu until game mode is chosen
        switch(menu(choice)){
            case PVCPU:
                cout << "Initializing Player vs. Computer game mode.\nEnter a 0 at any time to quit.\n";
                gameMode = PVCPU; //Initialize game mode
                cout << "Enter map size: ";
                cin >> size;
                cout << "Initializing CPU ships...\n";
                cpu.ships = initCPU(size);
                for (int i = 0; i < size; i++){
                    for (int j = 0; j < size; j++){
                        cout << static_cast<int>(cpu.ships[i][j]) << ' ';
                    }
                    cout << endl;
                }
                cout << "Patrol: " << PATROL << endl << "Destroyer: " << DESTROY << endl << "Carrier: " << CARRIER << endl;
                //Initialize computer player ships
                cpuMap(cpu.ships, size, CARRIER);
                cpuMap(cpu.ships, size, DESTROY);
                cpuMap(cpu.ships, size);
                map(cpu.ships, size);
            case 0:
                cout << "Goodbye.\n";
                return 0;
                break;
        }
    }
    
    //Exit stage right or left!
    return 0;
}

//Validation
bool valid(char& input, char val1, char val2, string error){
    if (input == 0 || input == '0'){
        cout << "Goodbye!\n";
        exit(0);
    }
    while (input != val1 && input != val2 && input != 9){
        cout << error << endl;
        cin >> input;
    }
    return true;
}
bool valid(char& input, char val1, char val2, char val3, string error){
    if (input == 0 || input == '0'){
        cout << "Goodbye!\n";
        exit(0);
    }
    while (input != val1 && input != val2 && input != val3 && input != 9){
        cout << error << endl;
        cin >> input;
    }
    return true;
}
bool valid(char& input, char val1, char val2, char val3, char val4, string error){
    if (input == 0 || input == '0'){
        cout << "Goodbye!\n";
        exit(0);
    }
    while (input != val1 && input != val2 && input != val3 && input != val4 && input != 9){
        cout << error << endl;
        cin >> input;
    }
    return true;
}
bool max(char& input, char maxVal, string error){
    if (input == 0 || input == '0'){
        cout << "Goodbye!\n";
        exit(0);
    }
    while (input > maxVal && input != 9){
        cout << error << endl;
        cin >> input;
        input -= CHARNUM;
    }
    return true;
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
    cout << "3. Load game from file";
    cout << "4. Display last winner\n";
    cout << "0. Exit\n";
    
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

char** initCPU(const char size){
    //Dynamically allocate two dimensional array for ships
    char ** ships = new char*[size];
    for (int i = 0; i < size; i++){
        ships[i] = new char[size];
    }
    //Initialize ships
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            ships[i][j] = 0;
        }
    }
    return ships;
}

void cpuMap(char** ships, const char size, Mapping ship){
    char posX;  //Starting X-axis position of each ship
    char posY;  //Starting Y-axis position of each ship
    bool unique = false;
    
    if (rand()%2){ //Determine orientation of the ship
        //Vertical
        posX = rand()%size;
        posY = rand()%(size-ship);
        
        //Validate position
        char unique = false;
        while(!unique){
            for(int i = posY; i < posY + ship; i++){
                if (ships[posX][i] == 0){
                    unique = true;
                } else {
                    posX = rand()%size;
                    posY = rand()%(size-ship);
                }
            }
        }
        
        //Position ship
        for(char y = posY; y < posY + ship; y++)
            ships[posX][y] = ship;
    } else {
        //Vertical
        posX = rand()%(size-ship);
        posY = rand()%size;
        
        //Validate position
        while(!unique){
            for(int i = posX; i < posX + ship; i++){
                if (ships[i][posY] == 0){
                    unique = true;
                } else {
                    posX = rand()%(size-ship);
                    posY = rand()%size;
                }
            }
        }
        
        //Position ship
        for(char x = posX; x < posX + ship; x++)
            ships[x][posY] = ship;
    }
}