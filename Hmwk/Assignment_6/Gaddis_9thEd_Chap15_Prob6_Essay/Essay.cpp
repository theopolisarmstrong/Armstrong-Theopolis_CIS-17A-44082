/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/* 
 * File:   Essay.cpp
 * Author: Theopolis Armstrong
 * Created on May 16th, 2019, 10:04 AM
 * Purpose: Demonstrate Essay class
 */

#include <iostream>
#include "Essay.h"
using namespace std;

//const int Essay::GRAM_MAX = 30,
//        Essay::SPELL_MAX = 20,
//        Essay::LEN_MAX = 20,
//        Essay::CONT_MAX = 30;

Essay::Essay(int g, int s, int l, int c){
    if (g <= GRAM_MAX && s <= SPELL_MAX && l <= LEN_MAX && c <= CONT_MAX) {
        grammar = g;
        spelling = s;
        length = l;
        content = c;
        GradedActivity::setScore(g + s + l + c); //Set total score
    } else cout << "Error: Criteria scores out of range\n";
}

void Essay::setScore(int g, int s, int l, int c){
    if (g <= GRAM_MAX && s <= SPELL_MAX && l <= LEN_MAX && c <= CONT_MAX) {
        grammar = g;
        spelling = s;
        length = l;
        content = c;
        GradedActivity::setScore(g + s + l + c); //Set total score
    } else cout << "Error: Criteria scores out of range\n";
}

void Essay::setGrammar(int g){
    if (g <= GRAM_MAX){
        //Recalculate score
        score -= grammar;
        score += g;
        //Set criteria score
        grammar = g;
    } else cout << "Error: Grammar score out of range\n";
}

void Essay::setSpelling(int s){
    if (s <= SPELL_MAX){
        //Recalculate score
        score -= spelling;
        score += s;
        //Set criteria score
        spelling = s;
    } else cout << "Error: Spelling score out of range\n";
}

void Essay::setLength(int l){\
    if (l <= LEN_MAX){
        //Recalculate score
        score -= length;
        score += l;
        //Set criteria score
        length = l;
    } else cout << "Error: Length score out of range\n";
}

void Essay::setContent(int c){
    if (c < CONT_MAX){
        //Recalculate score
        score -= content;
        score += c;
        //Set criteria score
        content = c;
    } else cout << "Error: Content out of range\n";
}