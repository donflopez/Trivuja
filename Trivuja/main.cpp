//
//  main.cpp
//  Trivuja
//
//  Created by Francisco López Liébana on 08/04/13.
//  Copyright (c) 2013 Francisco López Liébana. All rights reserved.
//

#include <iostream>
#include <SDL/SDL.h>
#include "SDLmain.h"

struct prueba {
    int uno;
    int dos;
    int tres;
};

using namespace std;

int main(int argc, char** argv)
{
    prueba v[10];
    
    v[0].uno=34;
    
    cout<<v[0].uno<<endl;
    
    SDL_Init(SDL_INIT_EVERYTHING);
    
    SDL_SetVideoMode(640, 480, 32, SDL_DOUBLEBUF);
    
    SDL_Event event;
    bool isRunning = true;
    
    while (isRunning) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_KEYDOWN) {
                isRunning = false;
            }
        }
    }
    
    SDL_Quit();
    return 0;
}

