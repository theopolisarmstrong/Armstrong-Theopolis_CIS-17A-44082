/* 
 * File:   main.cpp
 * Author: Theopolis Armstrong
 * Created on February 10, 2019 12:00 PM
 * Purpose:  Sum Rows, Sum Columns, Grand Sum of an integer array
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <iomanip> //setw(10)
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=80;  //Max Columns much larger than needed.

//Function Prototypes Here
void read(int [][COLMAX],int &,int &);//Prompt for size then table
void sum(const int [][COLMAX],int,int,int[][COLMAX]);//Sum rows,col,grand total
void print(const int [][COLMAX],int,int,int);//Either table can be printed

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=80;           //Max Rows much larger than needed
    int array[ROW][COLMAX]={};  //Declare original array
    int augAry[ROW][COLMAX]={}; //Actual augmented table row+1, col+1
    int row,col;                
    
    //Input the original table
    read(array,row,col);
    
    //Augment the original table by the sums
    sum(array,row,col,augAry);
    
    //Output the original array
    cout<<endl<<"The Original Array"<<endl;
    print(array,row,col,10);//setw(10)
    
    //Output the augmented array
    cout<<endl<<"The Augmented Array"<<endl;
    print(augAry,row+1,col+1,10);//setw(10)
    
    //Exit
    return 0;
}
void read(int a[][COLMAX],int & rows,int & cols){
    cout << "Input a table and output the Augment row,col and total sums.\n";
    cout << "First input the number of rows and cols. <20 for each\n";
    cin >> rows >> cols;
    cout << "Now input the table.\n";
    for (int row = 0; row < rows; row++){
        for (int col = 0; col < cols; col++){
            cin >> a[row][col];
        }
    }
}//Prompt for size then table
void sum(const int a[][COLMAX],int rows,int cols,int augA[][COLMAX]){
    for (int row = 0; row < rows; row++){
        for (int col = 0; col < cols; col++){
            augA[row][col] = a[row][col];
        }
        int sum = 0;
        for (int col = 0; col < cols; col++){
            sum += augA[row][col];
        }
        augA[row][cols] = sum;
    }
    for (int col = 0; col < cols + 1; col++){
        int sum = 0;
        for (int row = 0; row < rows; row++)
            sum += augA[row][col];
        augA[rows][col] = sum;
    }
}//Sum rows,col,grand total
void print(const int a[][COLMAX],int rows,int cols,int width){
    for (int row = 0; row < rows; row++){
        for (int col = 0; col < cols; col++){
            cout << setw(width) << a[row][col];
        }
        cout << endl;
    }
}//Either table can be printed