/* 
 * File:   SavingsAccount.cpp
 * Author: Theopolis Armstrong
 * Created on June 5th, 2019, 3:53 PM
 * Purpose: SavingsAccount class definition
 */
#include <iostream>
using namespace std;
#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(float bal) : Balance(0), FreqWithDraw(0), FreqDeposit(0){
    if (bal > 0) Balance = bal;
}
void SavingsAccount::Transaction(float amount){
    Balance += Withdraw(amount) + Deposit(amount);
}
float SavingsAccount::Total(float savint, int time){
    float total = 1.0;
    savint++;
    for (int i = 0; i < time; i++){
        total *= savint;
    }
    total *= Balance;
    return total;
}
float SavingsAccount::TotalRecursive(float savint, int time){
    static float total = 1.0;
    if (time > 0){
        if (savint < 1) savint++;
        total*=savint;
        TotalRecursive(savint, time-1);
    }
    return total * Balance;
}
void SavingsAccount::toString(){
    cout << "Balance=" << Balance << endl;
    cout << "WithDraws=" << FreqWithDraw << endl;
    cout << "Deposits=" << FreqDeposit << endl;
}

float SavingsAccount::Withdraw(float amount){
    float check = 0.0;
    if (amount < 0){
        if (Balance+amount < 0){
            cout << "WithDraw not Allowed\n";
        } else {
            check = amount;
            FreqWithDraw++;
        }
    }
    return check;
}
float SavingsAccount::Deposit(float amount){
    if (amount > 0){
        FreqDeposit++;
        return amount;
    }
    return 0;
}