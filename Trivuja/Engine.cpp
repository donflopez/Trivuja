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

/**@brief:constructor de Engine que se encarga de dibujar el tablero con las casillas en pantalla
 * @param:un puntero screen(SDL_Surface) donde dibujaremos el tablero con las casillas(funciones draw propias de Board.cpp y Cassilla.cpp)
 * @pre:ninguna
 * @post:ninguna
 * @comentario:el tablero ocupa toda la pantalla pues crea una superficie de 640x480 que es el tamño del tablero(las casillas las dibuja encima)
 
 */
Engine::Engine(SDL_Surface *screen):keys(NULL){
    b = new Board(screen->format);
    alphaSurface = SDL_CreateRGBSurface(SDL_HWSURFACE, 640, 480, screen->format->BitsPerPixel, 0, 0, 0, 0);
    transparent.x=0;
    transparent.y=0;
    transparent.w=640;
    transparent.h=480;
    b->draw(screen);
    b->drawCasillas(screen);
}
/**@brief:dibuja las preguntas en pantalla,dandole al tablero transparencia para que se vean
 * @param:el tipo de pregunta(int) y un puntero screen a la superficie donde dibuja(SDL_Surface*)
 * @pre:ninguna
 * @post:ninguna
 
 */
void Engine::drawQuestion(int tQuest, SDL_Surface *screen){
    SDL_SetAlpha(alphaSurface, SDL_SRCALPHA, 180);
    SDL_BlitSurface(alphaSurface, NULL, screen, &transparent);
    questions.draw(tQuest, screen);
}
/**@brief:destructor de objetos Engine*/
 
Engine::~Engine(){
    b->~Board();
    questions.~QuestionEngine();
}