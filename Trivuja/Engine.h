//
//  Engine.h
//  Trivuja
//
//  Created by Francisco López Liébana on 15/04/13.
//  Copyright (c) 2013 Francisco López Liébana. All rights reserved.
//

#ifndef Trivuja_Engine_h
#define Trivuja_Engine_h

//Concept engine in mind

//IMPORTANT!!! This is not planning.

class Engine {
private:
    SDL_Event event;
    Uint8 *keys;
    SDL_Surface *screen;
    SDL_Rect rectangulo;
public:
    Engine(SDL_Surface *screen):screen(screen){};
    void drawScene();
};

#endif
