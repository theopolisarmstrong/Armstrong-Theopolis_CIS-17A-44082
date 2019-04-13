/*
 * File:   main.cpp
 * Author: Theopolis Armstrong
 * Created on April 13, 2019
 * Purpose: Project 1 - Battleship 3
 *
 * Title raw ASCII art generated using http://www.patorjk.com/software/taag/
 *
 * Will not compile, incomplete integration of structure
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
const unsigned char MAP = 5; //Size of the map

//Enumerators

//Structures
struct Player{
    char * ships; //Dynamically allocated array of ship positions
    char * health = {1, 2, 3}; //health of ships; health[1]=carrier, health[2]=destroyer, health[3]=patrol
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
void initP(char *);
char** initCPU(const char size);
void map(const char** ships, const char size);   //Output map
void cpuMap(char**, const char, const unsigned char);   //Generate computer player ship positions
void pMap(char ships[][MAP], unsigned char type = 1);   //Input player 1 ship positions
//void sunk(char health[]);     requires ship positions validation
void genTar(char& targetX, char& targetY);  //Generate unique random targets for computer player
void updateV(char x, char y, vector<char>& pastX, vector<char>& pastY);
bool turn(char targetX, char targetY, char health[], char ships[][MAP], vector<char>& turns);  //Player turn; pass opposing player's ship placements for comparison
bool testEnd(char ships[][MAP]);  //Has the game ended?
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
    const unsigned char CPU = 1;  //CPU win condition
    const unsigned char P1 = 2;   //Player 1 win condition
    const unsigned char P2 = 3;   //Player 2 win condition
    const unsigned char CARRIER = 3; //index of aircraft carrier for health and position
    const unsigned char DESTROY = 2; //index of destroyer for health and position
    const unsigned char PATROL = 1;  //index of patrol boat for health and position
    
    const string WIN = "win.dat";
    const string SAVE = "save.dat";
    
    bool end = false;   //end game flag
    char winner = 0;    //winner of the game
    char gameMode = 0;  //game mode chosen in menu
    char choice;    //menu choice
    char size;
    Player p1, p2, cpu;
    
//    char p1Ships[MAP][MAP] = {0};  //positions of player 1 ships w/ test initialization
//    char p2Ships[MAP][MAP] = {0};  //positions of player 2 ships
//    char cShips[MAP][MAP] = {0}; //positions of computer player ships
//    char p1Heal[] = {1, 2, 3};  //health of player 1 ships; heal[1] =carrier heal[2]=destroyer heal[3]=patrol
//    char p2Heal[] = {1, 2, 3};  //health of player 2 ships
//    char cHeal[] = {1, 2, 3};  //health of player 3 ships
    
    char targetX, targetY;  //Target coordinates
    
//    vector<char> p1Turns;   //total turns taken by player 1, player 2 and CPU; 1 = hit, 0 = miss
//    vector<char> p2Turns;
//    vector<char> cTurns;
    
    string hit;   //Indicates a hit
    string winName; //Name of the winner
    float health = 0.0f;   //hit percentage of player 1, player 2, and CPU
    
    //Initialize game
    title();
    while(!gameMode){   //Loop menu until game mode is chosen
        switch(menu(choice)){
            case PVCPU:
                cout << "Initializing Player vs. Computer game mode.\nEnter a 0 at any time to quit.\n";
                //Initialize game mode and ships
                gameMode = PVCPU;   //Initialize game mode
                cout << "Enter map size: ";
                cin >> size;
                cout << "Initializing CPU ships...\n";
                cpu.ships = initCPU(size);
                //Initialize computer player ships
                cpuMap(cpu.ships, size, CARRIER);
                cpuMap(cpu.ships, size, DESTROY);
                cpuMap(cpu.ships, size);
                map(cpu.ships, size);
                //Initialize player ship positions
                cout << "Place you Aircraft Carrier.\n";
                pMap(p1Ships, CARRIER);
                cout << "Place you Destroyer.\n";
                pMap(p1Ships, DESTROY);
                cout << "Place you Patrol Boat.\n";
                pMap(p1Ships, PATROL);
                cout << endl;
                break;
            case PVP:
                cout << "Initializing Player vs. Player game mode.\nEnter a 0 at any time to quit.\n";
                //Initialize game mode and ships
                gameMode = PVP;
                cout << "Player 1:\n";
                cout << "Place you Aircraft Carrier.\n";
                pMap(p1Ships, CARRIER);
                cout << "Place you Destroyer.\n";
                pMap(p1Ships, DESTROY);
                cout << "Place you Patrol Boat.\n";
                pMap(p1Ships);
                cout << endl;
                cout << "Player 2:\n";
                cout << "Place you Aircraft Carrier.\n";
                pMap(p2Ships, CARRIER);
                cout << "Place you Destroyer.\n";
                pMap(p2Ships, DESTROY);
                cout << "Place you Patrol Boat.\n";
                pMap(p2Ships);
                cout << endl;
                break;
            case 4: //load last win
                loadWin(WIN);
                break;
            case 0:
                cout << "Goodbye.\n";
                return 0;
                break;
        }
    }
    
    //Gameplay loop
    switch(gameMode){
        //Player vs. CPU
        case PVCPU:
            while(!end){
                //Player turn
                cout << "Player's turn: \n";
                cout << "Enter a target coordinates: ";
                cin >> targetX;
                targetX -= CHARNUM;
                max(targetX, MAP,  "Error: Target x-axis out of range.\n"); //Validate target x coordinate
                cin >> targetY;
                targetY -= CHARNUM;
                max(targetY, MAP, "Error: Target y-axis out of range.\n");  //Validate target y coordinate
                turn(targetX, targetY, cHeal, cShips, p1Turns) ? hit = "Hit!\n" : hit = "Miss!\n";
                map(p1Ships);
                cout << hit << endl;
                
                cout << "Health: ";
                health = 0.0f;
                for (char i : p1Heal){
                    cout << static_cast<int>(i) << ' ';
                    health += i;
                }
                cout << "Total health: " << (health / 6) * 100;
                cout << endl;
                    
                //Test for computer loss
                if (testEnd(cShips)){
                    end = true;
                    winner = P1;
                }
                
                //Computer Turn
                cout << "Computer's turn: \n";
                genTar(targetX, targetY);
                turn(targetX, targetY, p1Heal, p1Ships, cTurns) ? hit = "Computer hits!\n" : hit = "Computer misses!\n";  //take computer's turn using random X and Y target coord's 1-5
                cout << hit;
                //Test for player loss
                if (testEnd(p1Ships)){
                    end = true;
                    winner = CPU;
                }
            }
            break;
            
        //Player vs Player
        case PVP:
            while(!end){
                //Player 1 turn
                //Initialize target coordinates
                cout << "Player 1's turn: \n";
                map(p1Ships);
                cout << "Enter a target coordinates: ";
                cin >> targetX;
                targetX -= CHARNUM;
                max(targetX, MAP,  "Error: Target x-axis out of range.\n"); //Validate target x coordinate
                cin >> targetY;
                targetY -= CHARNUM;
                max(targetY, MAP, "Error: Target y-axis out of range.\n");  //Validate target y coordinate
                turn(targetX, targetY, cHeal, p2Ships, p1Turns) ? hit = "Hit!\n" : hit = "Miss!\n";
                cout << hit;
                cout << "Health: ";
                health = 0.0f;
                for (char i : p1Heal){
                    cout << static_cast<int>(i) << ' ';
                    health += i;
                }
                cout << "Total health: " << (health / 6) * 100;
                cout << endl;
                //Test for player 2 loss
                if (testEnd(p2Ships)){
                    end = true;
                    winner = P1;
                }
                
                //Player 2 Turn
                //Initialize target coordinates
                cout << "Player 2's turn: \n";
                map(p2Ships);
                cout << "Enter a target coordinates: ";
                cin >> targetX;
                targetX -= CHARNUM;
                max(targetX, MAP,  "Error: Target x-axis out of range.\n"); //Validate target x coordinate
                cin >> targetY;
                targetY -= CHARNUM;
                max(targetY, MAP, "Error: Target y-axis out of range.\n");  //Validate target y coordinate
                turn(targetX, targetY, p2Heal, p1Ships, p2Turns) ? hit = "Hit!\n" : hit = "Miss!\n";
                //            cout << "CPU map: \n";
                //            map(cShips);
                cout << hit;
                cout << "Health: ";
                health = 0.0f;
                for (char i : p2Heal){
                    cout << static_cast<int>(i) << ' ';
                    health += i;
                }
                cout << "Total health: " << (health / 6) * 100;
                cout << endl;
                //Test for player 1 loss
                if (testEnd(p1Ships)){
                    end = true;
                    winner = P2;
                }
                
            }
            break;
    }
    
    //Display the outputs
    switch (winner){
        case CPU:
            
            cout << "Computer wins!\n";
            bubble(cTurns);
            cout << "Hit ratio chart: \n";
            chart(cTurns);
            cout << endl;
            winName = "Computer";
            saveWin(WIN, winName, cTurns);
            break;
        case P1:
            cout << "Player 1 wins!\n";
            bubble(p1Turns);
            cout << "Hit ratio chart: \n";
            chart(p1Turns);
            cout << endl;
            winName = "Player 1";
            saveWin(WIN, winName, p1Turns);
            break;
        case P2:
            cout << "Player 2 wins!\n";
            bubble(p2Turns);
            cout << "Hit ratio chart: \n";
            chart(p2Turns);
            cout << endl;
            winName = "Player 1";
            saveWin(WIN, winName, p2Turns);
            break;
    }
    
    //Exit stage right or left!
    return 0;
}

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

void bubble(vector<char>& a){
    int index;
    for (int i = a.size() - 1; i > 0; i--){
        for (int j = 0; j < i; j++){
            if (a[j] > a[j + 1]){
                char temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
void select(vector<char>& a){
    for (int start = 0; start < a.size() - 1; start++){
        char min = a[start];
        int minPos = start;
        for (int i = start + 1; i < a.size(); i++){
            if (a[i] < min){
                min = a[a.size()];
                minPos = i;
            }
        }
        char temp = a[start];
        a[start] = a[minPos];
        a[minPos] = temp;
    }
}//Sort by row

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

void map(const char ships[][MAP]){
    //Output column headers and top divider
    cout << "     ";
    for (char i = 0; i < MAP * 6; i++){ //iterate though each space in the map output; map size * 6 characters per cell - 3 header characters
        if (i % 6 == 0)
            cout << i / 6 + 1;
        else
            cout << ' ';
    }
    cout << endl << "   ";
    for (char i = 0; i < MAP * 6 - 1; i++){
        cout << '-';
    }
    cout << endl;
    
    //Output table body and row headers
    for(char row = 0; row < MAP; row++){
        //Padding row
        cout << "  |";
        for (int i = 0; i < MAP; i++){
            cout << "     |";
        }
        cout << endl;
        
        //Data row
        cout << row + 1 << " |  ";
        for(char col = 0; col < MAP; col++){
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
        for (int i = 0; i < MAP; i++)
            cout << "     |";
        cout << endl;
        
        //Dividing row
        cout << "   ";
        for (char i = 0; i < MAP * 6 - 1; i++){
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

void cpuMap(char** ships, const char size, const unsigned char ship){
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

void pMap(char ships[][MAP], unsigned char ship){
    cout << endl << "Position your ship: \n";
    bool repos; //positioning loop flag
    char answer;    //positioning loop prompt input
    char orient = 'v';  //ship orientation
    char posX;  //Starting X-axis position of each ship
    char posY;  //Starting Y-axis position of each ship
    
    //Begin positioning ship
    do{
        map(ships);
        
        //Determine orientation of the ship
        if (ship != 1){
            cout << "Is your ship vertical or horizontal [V/h]? ";
            cin >> orient;
            valid(orient, 'v', 'h', 'V', 'H', "Error: Invalid orientation");
        }
        
        //Position the ship in the correct orientation
        switch(orient){
            case 'v':
            case 'V':{
                //Input ship position
                cout << "Enter the top-most coordinates of the ship (ex. '2 5'): ";
                cin >> posX;
                posX -= CHARNUM; //Convert ASCII code to integer
                max(posX, MAP, "Error: Invalid y-axis (ensure the ship would not protrude outside the map)\nEnter a new y-axis value: ");
                cin >> posY;
                posY -= CHARNUM; //Convert ASCII code to integer
                max(posY, MAP - (ship - 1), "Error: Invalid y-axis (ensure the ship would not protrude outside the map)\nEnter a new y-axis value: ");
                
                //Position ship
                for(char row = posY; row < posY + ship; row++){
                    ships[row - 1][posX - 1] = ship;
                }
                break;
            }
            case 'h':
            case 'H':{
                //Input ship position
                cout << "Enter the top-most coordinates of the ship (ex. '3 1'): ";
                cin >> posX;
                posX -= CHARNUM; //Convert ASCII code to integer
                max(posX, MAP - (ship - 1), "Error: Invalid x-axis (ensure the ship would not protrude outside the map)\nEnter a new x-axis value: ");
                cin >> posY;
                posY -= CHARNUM; //Convert ASCII code to integer
                max(posY, MAP, "Error: Invalid y-axis (ensure the ship would not protrude outside the map)\nEnter a new y-axis value: ");
                
                //Position ship
                for(char col = posX; col < posX + ship; col++){
                    ships[posY - 1][col - 1] = ship;
                }
                break;
            }
        }
        cout << "Your ships: \n";
        map(ships);
        
        //Prompt for repositioning
        repos = false;
        cout << "Would you like to reposition your ship [N/y]? ";
        cin >> answer;
        valid(answer, 'y', 'n', 'Y', 'N', "Error: Invalid answer");
        if (answer == 'y' || answer == 'Y')
            repos = true;
    }while(repos);
}

void updateV(char x, char y, vector<char>& pastX, vector<char>& pastY){
    pastX.push_back(x);
    pastY.push_back(y);
}

void genTar(char& targetX, char& targetY){
    static vector<char> pastX;  //Previous X-axis targets
    static vector<char> pastY;  //Previous Y-axis targets
    
    //Initialize targets with random coordinates
    targetX = rand()%MAP+1;
    targetY = rand()%MAP+1;
    
    //Generate unique random X and Y targets
    for(int i = 0; i < pastX.size(); i++){
        if (targetX == pastX[i] && targetY == pastY[i]){
            i = 0;
            targetX = rand()%MAP;
            targetY = rand()%MAP;
        }
    }
    //Update past target vectors
    updateV(targetX, targetY, pastX, pastY);
    
    cout << "The computer targets (" << static_cast<int>(targetX) << ", " << static_cast<int>(targetY) << ")." << endl;
    cout << endl;
}

bool turn(char targetX, char targetY, char health[], char ships[][MAP], vector<char>& turns){
    const unsigned char CARRIER = 3; //Index of aircraft carrier for health and position
    const unsigned char DESTROY = 2; //Index of destroyer for health and position
    const unsigned char PATROL = 1;  //Index of patrol boat for health and position
    const unsigned char MISS = -1;   //Indicator of a miss
    const unsigned char HIT = -2;   //Indicator of a hit ship
    
    targetX -= 1;
    targetY -= 1;
    if (ships[targetY][targetX] > 0){   //Ship is present
        //Modify ship health
        switch(ships[targetY][targetX]){
            case CARRIER:
                health[CARRIER-1] -= 1;
                break;
            case DESTROY:
                health[DESTROY-1] -= 1;
                break;
            case PATROL:
                health[PATROL-1] -= 1;
                break;
        }
        //Indicate ship hit on map
        ships[targetY][targetX] = HIT;
        turns.push_back(HIT);
        //Notify ship hit
        return true;
    } else if (ships[targetY][targetX] == 0){   //Ship is not present
        ships[targetY][targetX] = MISS;
        turns.push_back(MISS);
        return false;
    } else if (ships[targetY][targetX] == -1 || ships[targetY][targetY] == -2){ //Target coordinates previously targeted
        turns.push_back(MISS);
        return false;
    } else return false;
}

bool testEnd(char ships[][MAP]){
    bool end = true;    //End gameplay loop flag
    for (int row = 0; row < MAP; row++){
        for (int col = 0; col < MAP; col++){
            if (ships[row][col] > 0)
                end = false;
        }
    }
    return end;
}

void chart(vector<char> turns){
    for (char i : turns){
        switch(i){
            case -1:
                cout << "O ";
                break;
            case -2:
                cout << "X ";
                break;
        }
    }
        cout << endl;
}

void loadWin(string file){
    ifstream win(file);
    string out;
    string winner;
    string chart;
    win >> winner;
    while(win >> chart);
    cout << endl;
    cout << "Previous winner : " << winner << endl;
    cout << "Hit chart: " << chart << endl;
    cout << endl;
    win.close();
}

void saveWin(string file, string winner, vector<char> turns){
    cout << "Saving win...";
    ofstream win("win.dat");
    win << winner << endl;
    for (char i : turns){
        switch(i){
            case -1:
                win << "O";
                break;
            case -2:
                win << "X";
                break;
        }
    }
    cout << "\tSaved.";
    win.close();
}
