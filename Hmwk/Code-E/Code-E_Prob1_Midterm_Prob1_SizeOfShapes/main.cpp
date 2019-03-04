/* 
 * Author: Theopolis Armstrong
 * Created on January 27, 2019
 * Purpose:  Output an ASCII art of a given letter using the a given size
 */

//System Libraries
#include <iomanip>
#include <iostream>  //Input/Output Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes
void prompt (char& size, char& shape);  //prompts and stores user input for size and shape of output design
bool isEven (char size);    //determines whether a number is even or odd
void cross (char size); //outputs cross shape
void evenX (char size);    //generates even cross shape
void oddX (char size); //generates odd cross shape
void bSlash (char size);   //outputs backslash shape
void slash (char size);    //outputs forwards slash shape

void vOutput (char size, char shape);  //verbose output for testing/debugging

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    char size; //size of output
    char shape; //shape of output
    
    //Initialize or input i.e. set variable values
    cout << "Create a numbered shape that can be sized.\n";
    prompt(size, shape);
    
    //Map inputs -> outputs
    switch(shape){
        case 'x':
        case 'X':
            cross(size);
            break;
        case 'b':
        case 'B':
            bSlash(size);
            break;
        case 'f':
        case 'F':
            slash(size);
            break;
    }
    
    //Display the outputs
    //vOutput(size, shape);

    //Exit stage right or left!
    return 0;
}

void prompt (char& size, char& shape){
    cout << "Input an integer number [1,50] and a character [x,b,f].\n";
    short convert;  //convert character to integer
    cin >> convert >> shape;
    size = convert;
    
    //Input validation loop
    while ((size < 1 || size > 50) || ((shape != 'x' && shape != 'b' && shape != 'f') &&
                                        (shape != 'X' && shape != 'B' && shape != 'F'))){
        if (size < 1 || size > 50)  //validate size
            cout << "Error: Size is not between 1-50\n";
        
        if (shape != 'x' && shape != 'b' && shape != 'f')   //validate shape
            cout << "Error: Shape is not 'x', 'b', or 'f'.\n";
        
        cin >> size >> shape;
    }
}

bool isEven (char size){
    return size % 2 == 0 ? true : false;
}

void evenX (char size){
    //iterate through first half of cross
    for (char row = 0; row < size / 2; row++){
        char num1 = row + 1, //first number in a row
                num2 = size - row;   //second number in a row
        char gapMax = num2 - num1 - 1;    //amount of spaces between the numbers

        //output alignment spacing
        for (char spaces = 0; spaces < row; spaces++){
            cout << " ";
        }

        cout << static_cast<unsigned short>(num1);
        
        for (char spaces = 0; spaces < gapMax; spaces++)    //output middle spaces
            cout << " ";

        cout << static_cast<unsigned short>(num2);
        
        for (char spaces = 0; spaces < row; spaces++)   //output trailing spaces
            cout << " ";

        cout << endl;
    }
    
    //output through second half of cross
    for (char row = size / 2 - 1; row >= 0; row--){   
        char num1 = row + 1, //first number in a row
                num2 = size - row;   //second number in a row
        char gapMax = num2 - num1 - 1;    //amount of spaces between the numbers
        
        for (char spaces = 0; spaces < row; spaces++){  //output alignment spacing
            cout << " ";
        }

        cout << static_cast<unsigned short>(num1);

        
        for (char spaces = 0; spaces < gapMax; spaces++){   //output middle spaces
            cout << " ";
        }

        cout << static_cast<unsigned short>(num2);
        
        for (char spaces = 0; spaces < row; spaces++)   //output trailing spaces
            cout << " ";

        cout << endl;
    }
}

void oddX (char size){
    //iterate through first half of cross
    for (char row = 0; row < size / 2; row++){   
        char num1 = size - row,    //first number in a row
                num2 = row + 1;   //second number in a row
        char gapMax = num1 - num2 - 1; //amount of spaces between the numbers
        
        for (char spaces = 0; spaces < row; spaces++)  //output alignment spacing
            cout << " ";

        cout << static_cast<unsigned short>(num1);
        
        for (char spaces = 0; spaces < gapMax; spaces++)    //output middle spaces
            cout << " ";

        cout << static_cast<unsigned short>(num2);
        
        for (char spaces = 0; spaces < row; spaces++)   //output trailing spaces
            cout << " ";

        cout << endl;
    }

    //output middle row
    for (char spaces = 0; spaces < (size - 1) / 2; spaces++)    //alignment spacing
        cout << " ";
    cout << size / 2 + 1;
    for (char spaces = 0; spaces < (size - 1) / 2; spaces++)    //trailing spaces
            cout << " ";
    cout << endl;


    //output through second half of cross
    for (char row = size / 2 - 1; row >= 0; row--){
        char num1 = size - row,    //first number in a row
                num2 = row + 1;   //second number in a row
        char gapMax = num1 - num2 - 1; //amount of spaces between the numbers
        
        for (char spaces = 0; spaces < row; spaces++)  //output alignment spacing
            cout << " ";

        cout << static_cast<unsigned short>(num1);
        
        for (char spaces = 0; spaces < gapMax; spaces++)   //output middle spaces
            cout << " ";

        cout << static_cast<unsigned short>(num2);
        
        for (char spaces = 0; spaces < row; spaces++)   //output trailing spaces and end line
            cout << " ";
        cout << endl;
    }
}

void cross (char size){
    if (isEven(size)){
        evenX(size);
    } else {
        oddX(size);
    }
}

void bSlash (char size){
    for (char row = 0; row < size; row++){ //rows count descending order
        for (char spaces = 0; spaces < row; spaces++)    //output preceding spaces
            cout << " ";


        if (isEven(size))   //output number; if odd, output numbers in descending order
            cout << row + 1; 
        else 
            cout << size - row;


        for (char spaces = 0; spaces < size - row - 1; spaces++)    //output trailing spaces
            cout << " ";
        cout << endl;
    }
}

void slash (char size){
    for (char row = 0; row < size; row++){ //iterate through rows
        for (char spaces = 0; spaces < size - row - 1; spaces++)    //output preceding spaces
            cout << " ";
        
        if(isEven(size))    //output number: if odd, print in descending order
            cout << size - row;
        else
            cout << row + 1;
        
        for (char spaces = 0; spaces < row; spaces++)    //output trailing spaces and end line
            cout << " ";
        cout << endl;
    }
}

void vOutput (char size, char shape){
    cout << "Size: " << size << endl 
            << "Shape: " << shape << endl;
    if (isEven(size))
        cout << "Size is even";
    else 
        cout << "Size is odd";
}