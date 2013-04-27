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
    string line;
    
    file.open("/Users/donflopez/Downloads/preguntas.tjData");
    if(file.good()){
        while (file.eof()!=true) {
            getline(file,line);
            std::cout << "Pregunta: " << line << std::endl;
        }
    }
}

QandA QuestionEngine::getQuestion(int type){
    return questions[type][rand()%20];
}