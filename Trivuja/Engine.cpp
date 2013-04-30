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

Engine::Engine():keys(NULL) {
    this->screen = SDL_SetVideoMode(640, 480, 24, SDL_HWSURFACE);
    if (screen == NULL){
        std::cout << "No se puede inicializar el modo gráfico: " << SDL_GetError() << std::endl;
    }
    else {
        b = new Board(this->screen->format);
        b->draw(screen);

    }
}

Engine::Engine(SDL_Surface *screen):keys(NULL){
    b = new Board(screen->format);
    this->screen=screen;
    b->draw(this->screen);
    b->drawCasillas(this->screen);
}

Engine::~Engine(){
    b->~Board();
    this->screen->SDL_Surface::~SDL_Surface();
}