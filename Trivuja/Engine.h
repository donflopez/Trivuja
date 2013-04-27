//
//  Engine.h
//  Trivuja
//
//  Created by Francisco López Liébana on 15/04/13.
//  Copyright (c) 2013 Francisco López Liébana. All rights reserved.
//

#ifndef Trivuja_Engine_h
#define Trivuja_Engine_h

#include "Board.h"
//Concept engine in mind

//IMPORTANT!!! This is not planning.

class Engine {
private:
    Board b;
    SDL_Event event;
    Uint8 *keys;
    SDL_Surface *screen;
    SDL_Rect rectangulo;
public:
    Engine();
    Engine(SDL_Surface *screen):screen(screen){b.draw(this->screen);};
    void drawScene();
    
};

#endif
