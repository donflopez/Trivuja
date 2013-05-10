//
//  Casilla.cpp
//  Trivuja
//
//  Created by Francisco López Liébana on 28/04/13.
//  Copyright (c) 2013 Francisco López Liébana. All rights reserved.
//

#include <iostream>

#include "Casilla.h"


/**@brief:contructor de las casillas que asigna a cada tipo(0-5) un color, y un rectángulo de 50x50 pixeles
 * @param:el tipo de casilla(0-5),un puntero format(SDL_PixelFormat) para darr color y las coordenadas de la casilla x e y(int)
 * @pre:ninguna
 * @post:ninguna
 
 */
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
/**@brief:dibuja la casilla en una superrfice(screen)
 * @param:un puntero a la superficie donde la dibujamos(en pantalla) de tipo SDL_Surface
 * @pre:niguna
 * @post:ninguna
 
 */
void Casilla::draw(SDL_Surface *screen){
    SDL_FillRect(screen, &rect, color[selected]);
}