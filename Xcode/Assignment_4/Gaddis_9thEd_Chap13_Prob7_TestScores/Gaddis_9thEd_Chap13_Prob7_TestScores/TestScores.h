/*
 * File:   TestScores.h
 * Author: Theopolis Armstrong
 * Created on May 5th, 2019, 5:32 PM
 * Purpose: TestScores class declaration
 * ---------------------------------------------------
 * |                  TestScores                     |
 * |-------------------------------------------------|
 * | - scores : int[3]                               |
 * |-------------------------------------------------|
 * | + TestScores() :                                |
 * | + setScore(score : int, index : char) : void    |
 * | + getScore() : int                              |
 * | + getAvg() : int                                |
 * ---------------------------------------------------
 */

#ifndef TestScores_h
#define TestScores_h

#include <iostream>
using namespace std;

class TestScores{
private:
    int scores[3];
public:
    TestScores();
    void setScore(int score, char index){ scores[index] = score; }
    int getScore(int index) { return scores[index]; }
    int getAvg();
};

#endif /* TestScores_h */
