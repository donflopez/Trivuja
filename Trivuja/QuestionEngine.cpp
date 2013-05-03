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
    //Setting font colors
    //Background
    bgcolor.r=255;
    bgcolor.g=0;
    bgcolor.b=0;
    //Question
    qfcolor.r=32;
    qfcolor.g=178;
    qfcolor.b=170;
    //Answer
    afcolor.r=255;
    afcolor.g=255;
    afcolor.b=255;
    
    for (int i=0; i<4; i++) {
        rect[i].y = 20+(i*50);
        rect[i].x = (i==0) ? 20 : 50;
        rect[i].w = (i==0) ? 500 : 470;
    }
    
    font = TTF_OpenFont("/Library/Fonts/Arial.ttf", 30);
    ifstream file;
    stringstream ss, iss;
    string line, sType;
    string question, answ[3];
    int type, correct, i=0;
    std::cout << "Constructor de QuestionEngine" << std::endl;
    file.open("/Users/Donflopez/Downloads/preguntas.tjData");
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
            std::cout << "Pregunta " << i << " tipo " << type << ":" << questions[type][i]->getQuestion() << std::endl;
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

void QuestionEngine::draw(int type, SDL_Surface *screen){
    int qNumber = rand()%20;
    char* question = new char[questions[type][qNumber]->getQuestion().length()+1];
    strcpy(question, questions[type][qNumber]->getQuestion().c_str());
    sFont = TTF_RenderUTF8_Blended(font, question, qfcolor);
    SDL_SetColorKey(sFont,SDL_SRCCOLORKEY|SDL_RLEACCEL, SDL_MapRGB(sFont->format,255,0,0));
    SDL_BlitSurface(sFont, NULL, screen, &rect[0]);
    sFont = TTF_RenderUTF8_Blended(font, questions[type][qNumber]->getAnswer(0).c_str(), qfcolor);
    SDL_SetColorKey(sFont,SDL_SRCCOLORKEY|SDL_RLEACCEL, SDL_MapRGB(sFont->format,255,0,0));
    SDL_BlitSurface(sFont, NULL, screen, &rect[1]);
    sFont = TTF_RenderUTF8_Blended(font, questions[type][qNumber]->getAnswer(1).c_str(), qfcolor);
    SDL_SetColorKey(sFont,SDL_SRCCOLORKEY|SDL_RLEACCEL, SDL_MapRGB(sFont->format,255,0,0));
    SDL_BlitSurface(sFont, NULL, screen, &rect[2]);
    sFont = TTF_RenderUTF8_Blended(font, questions[type][qNumber]->getAnswer(2).c_str(), qfcolor);
    SDL_SetColorKey(sFont,SDL_SRCCOLORKEY|SDL_RLEACCEL, SDL_MapRGB(sFont->format,255,0,0));
    SDL_BlitSurface(sFont, NULL, screen, &rect[3]);
}

QuestionEngine::~QuestionEngine(){
    //TTF_CloseFont(font);
    //SDL_FreeSurface(sFont);
}