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

void Engine::drawQuestion(int tQuest, SDL_Surface *screen){
    SDL_SetAlpha(alphaSurface, SDL_SRCALPHA, 180);
    SDL_BlitSurface(alphaSurface, NULL, screen, &transparent);
    questions.draw(tQuest, screen);
}

void Engine::next(SDL_Surface *screen){
    int type = b->selectCasilla(6, screen);
    std::cout << "Type: " << type << std::endl;
    this->drawQuestion(type, screen);
    this->isQuestion=true;
    SDL_Flip(screen);
}

Engine::~Engine(){
    b->~Board();
    questions.~QuestionEngine();
}