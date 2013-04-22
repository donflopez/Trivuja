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

Engine::Engine() {
    this->screen = SDL_SetVideoMode(640, 480, 24, SDL_HWSURFACE);
    if (screen == NULL){
        std::cout << "No se puede inicializar el modo gráfico: " << SDL_GetError() << std::endl;
    }
    board.draw(screen);
}

