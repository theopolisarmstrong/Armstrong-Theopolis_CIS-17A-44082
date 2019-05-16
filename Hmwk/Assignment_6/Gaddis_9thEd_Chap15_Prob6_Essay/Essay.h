/* 
 * File:   Essay.h
 * Author: Theopolis Armstrong
 * Created on May 16th, 2019, 10:04 AM
 * Purpose: Demonstrate Essay class
 */

#ifndef ESSAY_H
#define ESSAY_H
#include "GradedActivity.h"

class Essay : public GradedActivity{
protected:
    //Max scores for each criteria
    static const int GRAM_MAX = 30,
                     SPELL_MAX = 20,
                     LEN_MAX = 20,
                     CONT_MAX = 30;
    //Criteria scores
    int grammar = 0,
        spelling = 0,
        length = 0,
        content = 0;
public:
    Essay(int, int, int, int); //Set criteria scores if in range
    void setScore(int, int, int, int); //Set all criteria scores
    //Mutator functions
    void setGrammar(int);
    void setSpelling(int);
    void setLength(int);
    void setContent(int);
    //Accessor functions
    int getGrammar() const { return grammar; }
    int getSpelling() const { return spelling; }
    int getLength() const { return length; }
    int getContent() const { return content; }
    
};

#endif /* ESSAY_H */

