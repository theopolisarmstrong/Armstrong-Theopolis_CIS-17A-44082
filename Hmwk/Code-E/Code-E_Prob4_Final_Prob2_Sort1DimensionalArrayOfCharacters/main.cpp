/* 
 * File:   main.cpp
 * Author: Theopolis Armstrong
 * Created on February 10, 2019 9:22AM
 * Purpose:  Sorting an array of characters if specified correctly
 */

//System Libraries Here
#include <iostream>//cout,cin
#include <cstring> //strlen()
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
int  read(char []);
void sort(char [],int);
void print(const char [],int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE=80;//Larger than needed
    char array[SIZE]; //Character array larger than needed
    int sizeIn,sizeDet;//Number of characters to be read, check against length
    
    //Input the size of the array you are sorting
    cout<<"Read in a 1 dimensional array of characters and sort"<<endl;
    cout<<"Input the array size where size <= 20"<<endl;
    cin>>sizeIn;
    
    //Now read in the array of characters and determine it's size
    cout<<"Now read the Array"<<endl;
    sizeDet=read(array);//Determine it's size
    
    //Compare the size input vs. size detected and sort if same
    //Else output different size to sort
    if(sizeDet==sizeIn){
        sort(array,sizeIn); //Sort the array
        print(array,sizeIn);//Print the array
    }else{
        cout<<(sizeDet<sizeIn?"Input size less than specified.":
            "Input size greater than specified.")<<endl;
    }
    
    //Exit
    return 0;
}
int  read(char chars[]){
    cin >> chars;
    return strlen(chars);
}
void sort(char chars[],int size){
    for (int start = 0; start < size - 1; start++){
        char min = chars[start];
        int minPos = start;
        for (int i = start + 1; i < size; i++){
            if (chars[i] < min){
                min = chars[i];
                minPos = i;
            }
        }
        char temp = chars[start];
        chars[start] = chars[minPos];
        chars[minPos] = temp;
    }
}
void print(const char chars[],int size){
    for (char c = 0; c < size; c++){
        cout << chars[c];
    }
    cout << endl;
}