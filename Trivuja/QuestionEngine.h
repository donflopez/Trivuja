//
//  QuestionEngine.h
//  Trivuja
//
//  Created by Francisco López Liébana on 27/04/13.
//  Copyright (c) 2013 Francisco López Liébana. All rights reserved.
//

#ifndef Trivuja_QuestionEngine_h
#define Trivuja_QuestionEngine_h

#include "QandA.h"
#include <SDL/SDL.h>
#include <SDL_ttf/SDL_ttf.h>

class QuestionEngine {
private:
    SDL_Color bgcolor, qfcolor, afcolor;
    SDL_Rect rect[4];
    SDL_Surface *sFont;
    TTF_Font *font;
    //TODO: Load dinamically QandA
    QandA* questions[5][20];
    int correct;
    //int latest[2];
public:
    QuestionEngine();
//QandA getQuestion(int type);
    void draw(int type, SDL_Surface *screen);
    bool isValid(int answ);
    void drawResult(bool correct, SDL_Surface *screen);
    void showAllQuestions();
    ~QuestionEngine();
};

#endif
