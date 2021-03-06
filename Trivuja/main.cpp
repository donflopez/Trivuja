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
#include "Engine.h"
#include <SDL_ttf/SDL_ttf.h>

using namespace std;

#define FPS 40

SDL_Event event;
Uint8 *keys;
SDL_Surface *screen, *aphaSurface;
SDL_Rect rectangulo;
Engine *eng;
TTF_Font *font;
Uint32 waittime = 1000.0f/FPS;
Uint32 framestarttime = 0;
Sint32 delaytime;

int main(int argc, char** argv)
{
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_JOYSTICK) < 0) {       //inicia las funciones de SDL
        printf("No se pudo iniciar SDL: %s\n",SDL_GetError());
        return 1;
    }
    screen = SDL_SetVideoMode(640,480,32,SDL_HWSURFACE|SDL_DOUBLEBUF); //establece el modo de video
    if (screen == NULL) {
        cout << "No se puede inicializar el modo gráfico: \n" << SDL_GetError();
        return 1; 
    }
    
    if (TTF_Init() < 0) {
        printf("No se pudo iniciar SDL_ttf: %s\n",SDL_GetError());
        return 1;
    }
    
    atexit(SDL_Quit);
    
    eng = new Engine(screen);
    
    atexit(SDL_Quit);
    
    SDL_Flip(screen);
    
    
    bool isRunning = true;
    
    while (isRunning) {
        keys = SDL_GetKeyState(NULL);
        if(keys[SDLK_n]&&!eng->showingQuestion()){
            eng->next(screen);
            eng->answer(keys, screen);
            sleep(3);
            eng->drawScene(screen);
        }
        
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                isRunning=false;
            if (event.type == SDL_KEYDOWN || event.type == SDL_JOYBUTTONDOWN)
                if (event.key.keysym.sym == SDLK_ESCAPE)
                    isRunning=false;
        }
    }
    
    SDL_Quit();
    
    eng->~Engine();
    delete eng;
    return 0;
}
