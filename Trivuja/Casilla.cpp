//
//  Casilla.cpp
//  Trivuja
//
//  Created by Francisco López Liébana on 28/04/13.
//  Copyright (c) 2013 Francisco López Liébana. All rights reserved.
//

#include <iostream>

#include "Casilla.h"

Casilla::Casilla(int type, const SDL_PixelFormat* format, int x, int y){
    this->type=type;
    selected = 0;
    switch(type){
        case 0:
            color[0] = SDL_MapRGB(format, 180, 0, 0);
            color[1] = SDL_MapRGB(format, 250, 0, 0);
            break;
        case 1:
            color[0] = SDL_MapRGB(format, 0, 180, 0);
            color[1] = SDL_MapRGB(format, 0, 250, 0);
            break;
        case 2:
            color[0] = SDL_MapRGB(format, 0, 0, 180);
            color[1] = SDL_MapRGB(format, 0, 0, 250);
            break;
        case 3:
            color[0] = SDL_MapRGB(format, 180, 180, 0);
            color[1] = SDL_MapRGB(format, 250, 250, 0);
            break;
        case 4:
            color[0] = SDL_MapRGB(format, 0, 180, 180);
            color[1] = SDL_MapRGB(format, 0, 250, 250);
            break;
        case 5:
            color[0] = SDL_MapRGB(format, 180, 180, 180);
            color[1] = SDL_MapRGB(format, 250, 250, 250);
            break;
    }
    rect.w=50;
    rect.h=50;
    rect.x=x;
    rect.y=y;
}

void Casilla::draw(SDL_Surface *screen){
    SDL_FillRect(screen, &rect, color[selected]);
}