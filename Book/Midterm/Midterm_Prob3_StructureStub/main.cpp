/* 
 * File:   main.cpp
 * Author: Theopolis Armstrong
 * Created on April 19, 2019, 10:48 AM
 * Purpose: Completed statistics problem.
 */

//Libraries
#include <iostream>//I/O
using namespace std;

//User Libraries
#include "Array.h"
#include "Stats.h"

//No Global Constants

//Function Prototypes I supply
Array *fillAry(int,int);        //Fill an array and put into a structure
void prntAry(const Array *,int);//Print the array 
int *copy(const int *,int);     //Copy the array
void mrkSort(int *,int);        //Sort an array
void prtStat(const Stats *);    //Print the structure
void rcvrMem(Array *);          //Recover memory from the Array Structure
void rcvrMem(Stats *);          //Recover memory from Statistics Structure

//Functions you are to supply
Stats *stat(const Array *);     //Find & store mean, median, & modes in structure

Array *mode(const Array*, int&); //Adaptation of Assignment 1 Gaddis_9thEd_Chap9_Prob8_Mode
float median(const Array*); //Adaptation of Assignment 1 Gaddis_9thEd_Chap9_Prob9_Median
float average(const Array*); //Calculates the average of an array

//Execution begins here
int main(int argc, char*argv[]) {
    //Declare variables and fill
    int arySize=8;//Array Size
    int modNum=10; //Number to control the modes (digits 0 to 9 allowed)
    Array *array=fillAry(arySize,modNum);
    
    //Print the initial array
    cout<<"Original Array"<<endl;
    prntAry(array,10);
    
    //Calculate some of the statistics
    Stats *stats=stat(array);
    
    //Print the statistics
    prtStat(stats);
    
    //Recover allocated memory
    rcvrMem(array);
    rcvrMem(stats);
    
    //Exit stage right
    return 0;
}

int *copy(const int *a,int n){
    //Declare and allocate an array
    //that is a c
    int *b=new int[n];
    //Fill
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
    //Return the copy
    return b;
}

void prtStat(const Stats *ary){
    cout<<endl;
    cout<<"The average of the array = "<<ary->avg<<endl;
    cout<<"The median of the array  = "<<ary->median<<endl;
    cout<<"The number of modes      = "<<
            ary->mode->size<<endl;
    cout<<"The max Frequency        = "<<
            ary->modFreq<<endl;
    if(ary->mode->size==0){
        cout<<"The mode set             = {null}"<<endl;
        return;
    }
    cout<<"The mode set             = {";
    for(int i=0;i<ary->mode->size-1;i++){
        cout<<ary->mode->data[i]<<",";
    }
    cout<<ary->mode->data[ary->mode->size-1]<<"}"<<endl;
}

void mrkSort(int *array,int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(array[j]<array[i]){
                int temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }
    }
}

void rcvrMem(Stats *stats){
    rcvrMem(stats->mode);
    delete stats;
}

void rcvrMem(Array *array){
    delete []array->data;
    delete array;
}

void prntAry(const Array *array,int perLine){
    //Output the array
    for(int i=0;i<array->size;i++){
        cout<<array->data[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

Array *fillAry(int n, int modNum){
    //Allocate memory
    Array *array=new Array;
    array->size=n;
    array->data=new int[array->size];
    
    //Fill the array with mod numbers
    for(int i=0;i<n;i++){
        array->data[i]=i%modNum;
    }
    
    //Exit function
    return array;
}

Stats *stat(const Array *array){
    //Non-working stub to be completed by the student
    cout<<endl<<"stat function to be completed by the student"<<endl;
    Stats *stats=new Stats;
    stats->mode=mode(array, stats->modFreq);
    stats->median=median(array);
    stats->avg = average(array);
    return stats;
}

Array *mode(const Array *array, int &modFreq){
    //Copy the array
    Array *ary = new Array;
    ary->data=copy(array->data,array->size);
    //Sort the copy
    mrkSort(ary->data,array->size);
    //Find the max Frequency
    char maxFreq = 1,    //Frequency of the mode(s)
            count = 1;  //Number of occurrences of a particular number
    for (int i = 1; i < array->size; i++){ //Loop through array
        if (ary->data[i-1] == ary->data[i]){ //Count matching numbers
            count++;
        } else count = 1; //Reset count when in a new group of numbers
        if (count > maxFreq) maxFreq = count;  //Set the max frequency to highest count
    }
    modFreq = maxFreq; //Return mode frequency
    
    //Find the number of modes
    int modes = 0; //number of modes
    count = 1; //reset count
    for (int i = 1; i < array->size; i++){ //Loop through array
        if (ary->data[i-1] == ary->data[i]){ //Count matching numbers
            count++;
        } else count = 1; //Reset count when in a new group of numbers
        if (count > 1 && count == maxFreq) modes++; //Increment mode count when a mode is found
    }
    
    //Allocate the mode array
    //Again this is just a stub.
    int nmodes=modes;  //Number of modes
    Array *modeAry=new Array;
    modeAry->size = nmodes;
    modeAry->data = new int[modeAry->size];
    
    
    //Fill the mode array
    int index = 0; //Index within mode array
    count = 1; //Reset count
    for (int i = 1; i < array->size; i++){ //Loop through array
        if (ary->data[i-1] == ary->data[i]){ //Count matching numbers
            count++;
        } else count = 1; //Reset count when in a new group of numbers
        if (count == maxFreq){  //Place number into mode array
            modeAry->data[index] = ary->data[i]; //Place mode into mode array
            index++;
        }
    }
    
    //Delete the allocated copy and return
    delete []ary;
    return modeAry;
}
float median(const Array* a){
    float med = 0; //Median
    
    //Copy array to new array
    int *sorted = new int(a->size);
    for (int i = 0; i < a->size; i++){
        sorted[i] = a->data[i];
    }
    
    //Selection sort new array
    int minIndex, min;
    for (int i = 0; i < a->size - 1; i++){
        minIndex = i;
        min = sorted[i];
        for (int j = i + 1; j < a->size; j++){
            if (sorted[j] < min){
                min = sorted[j];
                minIndex = j;
            }
        }
        int swap;
        swap = sorted[i];
        sorted[i] = sorted[minIndex];
        sorted[minIndex] = swap;
    }
    
    //Calculate median
    if (a->size == 0)
        med = 0;
    else if (a->size % 2 == 0)
        med = (sorted[(a->size - 1) / 2] + sorted[((a->size - 1) / 2) + 1]) / 2.0;
    else
        med = sorted[(a->size - 1) / 2];
    
    return med;
}
float average(const Array* a){
    float avg = 0;
    for (int i = 0; i < a->size; i++){
        avg += a->data[i];
    }
    avg /= a->size;
}