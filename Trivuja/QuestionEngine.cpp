//
//  QuestionEngine.cpp
//  Trivuja
//
//  Created by Francisco López Liébana on 27/04/13.
//  Copyright (c) 2013 Francisco López Liébana. All rights reserved.
//

#include "QuestionEngine.h"
#include <sstream>
#include <fstream>
#include <iostream>

QuestionEngine::QuestionEngine(){
    ifstream file;
    stringstream ss, iss;
    string line, sType;
    string question, answ[3];
    int type, correct, i=0;
    std::cout << "Constructor de QuestionEngine" << std::endl;
    file.open("/Users/donflopez/Downloads/questions.tjData");
    if(file.good()){
        while (file.eof()!=true) {
            getline(file,line);
            ss << line;
            getline(ss, sType, ';');
            iss<<sType;
            iss>>type;
            getline(ss, question, ';');
            getline(ss, answ[0], ';');
            getline(ss, answ[1], ';');
            getline(ss, answ[2], ';');
            getline(ss, sType, ';');
            iss<<sType;
            iss>>correct;
            questions[type][i] = new QandA(question, answ, correct);
            std::cout << "Pregunta " << i << ":" << questions[type][i]->getQuestion() << std::endl;
            if (i<20) {
                i++;
            }else {
                i=0;
            }
        }
    }
    
    /*for (int i=0; i<5; i++) {
        for (int j=0; j<20; j++) {
            questions[i][j]=new QandA();
        }
    }*/
}

//QandA QuestionEngine::getQuestion(int type){
//    return questions[type][rand()%20];
//}