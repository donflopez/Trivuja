//
//  QandA.cpp
//  Trivuja
//
//  Created by Francisco López Liébana on 27/04/13.
//  Copyright (c) 2013 Francisco López Liébana. All rights reserved.
//

#include "QandA.h"

QandA::QandA(string quest, string answ[], int cA){
    question=quest;
    for (int i=0; i<3; i++) {
        answer[i]=answ[i];
    }
    correctAnswer=cA;
}

bool QandA::isCorrect(int answ){
    if (answ==correctAnswer) {
        return true;
    }
    else{
        return false;
    }
}

string QandA::getQuestion(){
    return question;
}

string QandA::getAnswer(int nAns){
    return answer[nAns];
}

int QandA::getCorrectAns() {
    return correctAnswer;
}