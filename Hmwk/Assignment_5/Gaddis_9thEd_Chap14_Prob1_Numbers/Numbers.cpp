/* 
 * File:   Numbers.cpp
 * Author: Theopolis Armstrong
 * Created on May 12th, 2019, 8:39 PM
 * Purpose: Numbers class definition
 */

#include "Numbers.h"

string const Numbers::lessThan20[20] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
string const Numbers::greaterThan20[10] = {"zero", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
string const Numbers::hundred = "hundred";
string const Numbers::thousand = "thousand";

void Numbers::print(){
    //Split number into place values
    int ones = number % 10,
            tens = (number / 10) % 10,
            hundreds = (number / 100) % 10,
            thousands = (number / 1000) % 10;
    
    //Output thousands
    if (thousands > 0) cout << lessThan20[thousands] << ' ' << thousand << ' ';
    
    //Output hundreds
    if (hundreds > 0) cout << lessThan20[hundreds] << ' ' << hundred << ' ';
    
    //Output tens and ones
    if (tens > 0){
        if (tens > 1){
            cout << greaterThan20[tens] << ' '; 
            if (ones > 0) cout << lessThan20[ones] << endl;
        } else cout << lessThan20[(tens * 10) + ones] << endl;
    }
}
