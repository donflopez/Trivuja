//
//  QandA.h
//  Trivuja
//
//  Created by Francisco López Liébana on 27/04/13.
//  Copyright (c) 2013 Francisco López Liébana. All rights reserved.
//

#ifndef Trivuja_QandA_h
#define Trivuja_QandA_h

#include <string>

using namespace std;

class QandA {
private:
    string question;
    string answer[3];
    int correctAnswer;
    int type;
    
public:
    QandA();
    QandA(string quest, string answ[], int cA);
    bool isCorrect(int answ);
string getQuestion();
string getAnswer(int nAns);
};

#endif
