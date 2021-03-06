//
//  Board.h
//  Trivuja
//
//  Created by Francisco López Liébana on 15/04/13.
//  Copyright (c) 2013 Francisco López Liébana. All rights reserved.
//
#include "Casilla.h"
#include "CSprite.h"

#ifndef Trivuja_Board_h
#define Trivuja_Board_h

class Board: public CSprite{
private:
    CFrame brd;
    Casilla *casillas[36];
    
public:
    Board(const SDL_PixelFormat* format);
    Board(char *path, const SDL_PixelFormat* format);
    void setBoard(char* path);
    void drawCasillas(SDL_Surface *screen);
    int selectCasilla(int number, SDL_Surface *screen);
};

#endif
