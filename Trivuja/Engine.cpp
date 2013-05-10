//
//  Engine.cpp
//  Trivuja
//
//  Created by Francisco López Liébana on 15/04/13.
//  Copyright (c) 2013 Francisco López Liébana. All rights reserved.
//

#include <SDL/SDL.h>
#include <iostream>
#include "Engine.h"
#include "Board.h"
#include "Dice.h"

Engine::Engine(SDL_Surface *screen):keys(NULL),isQuestion(false){
    b = new Board(screen->format);
    alphaSurface = SDL_CreateRGBSurface(SDL_HWSURFACE, 640, 480, screen->format->BitsPerPixel, 0, 0, 0, 0);
    transparent.x=0;
    transparent.y=0;
    transparent.w=640;
    transparent.h=480;
    b->draw(screen);
    b->drawCasillas(screen);
}

void Engine::drawScene(SDL_Surface *screen){
    b->draw(screen);
    b->drawCasillas(screen);
    SDL_Flip(screen);
}

void Engine::drawQuestion(int tQuest, SDL_Surface *screen){
    SDL_SetAlpha(alphaSurface, SDL_SRCALPHA, 180);
    SDL_BlitSurface(alphaSurface, NULL, screen, &transparent);
    questions.draw(tQuest, screen);
}

void Engine::next(SDL_Surface *screen){
    Dice dice;
    int type = b->selectCasilla(dice.pull(), screen);
    std::cout << "Type: " << type << std::endl;
    if (type!=5) {
        this->drawQuestion(type, screen);
        this->isQuestion=true;
        SDL_Flip(screen);
    }
    else{
        this->isQuestion=false;
    }
}

void Engine::answer(Uint8* keys, SDL_Surface *screen){
    SDL_Event event;
    while (isQuestion) {
        SDL_PollEvent(&event);
        if(event.key.keysym.sym==SDLK_1){
            cout << "Respuesta 1" << endl;
            if(questions.isValid(0)){
                b->draw(screen);
                b->drawCasillas(screen);
                SDL_SetAlpha(alphaSurface, SDL_SRCALPHA, 180);
                SDL_BlitSurface(alphaSurface, NULL, screen, &transparent);
                questions.drawResult(true, screen);
                isQuestion=false;
                SDL_Flip(screen);
            }
            else{
                b->draw(screen);
                b->drawCasillas(screen);
                SDL_SetAlpha(alphaSurface, SDL_SRCALPHA, 180);
                SDL_BlitSurface(alphaSurface, NULL, screen, &transparent);
                questions.drawResult(false, screen);
                isQuestion=false;
                SDL_Flip(screen);
            }
        }
        else if(event.key.keysym.sym==SDLK_2){
            cout << "Respuesta 2" << endl;
            if(questions.isValid(1)){
                b->draw(screen);
                b->drawCasillas(screen);
                SDL_SetAlpha(alphaSurface, SDL_SRCALPHA, 180);
                SDL_BlitSurface(alphaSurface, NULL, screen, &transparent);
                questions.drawResult(true, screen);
                isQuestion=false;
                SDL_Flip(screen);
            }
            else{
                b->draw(screen);
                b->drawCasillas(screen);
                SDL_SetAlpha(alphaSurface, SDL_SRCALPHA, 180);
                SDL_BlitSurface(alphaSurface, NULL, screen, &transparent);
                questions.drawResult(false, screen);
                isQuestion=false;
                SDL_Flip(screen);
            }
        }
        else if(event.key.keysym.sym==SDLK_3){
            cout << "Respuesta 3" << endl;
            if(questions.isValid(2)){
                b->draw(screen);
                b->drawCasillas(screen);
                SDL_SetAlpha(alphaSurface, SDL_SRCALPHA, 180);
                SDL_BlitSurface(alphaSurface, NULL, screen, &transparent);
                questions.drawResult(true, screen);
                isQuestion=false;
                SDL_Flip(screen);
            }
            else {
                b->draw(screen);
                b->drawCasillas(screen);
                SDL_SetAlpha(alphaSurface, SDL_SRCALPHA, 180);
                SDL_BlitSurface(alphaSurface, NULL, screen, &transparent);
                questions.drawResult(false, screen);
                isQuestion=false;
                SDL_Flip(screen);
            }
        }
        
    }
}

void Engine::showAll(){
    questions.showAllQuestions();
}

Engine::~Engine(){
    b->~Board();
    questions.~QuestionEngine();
}