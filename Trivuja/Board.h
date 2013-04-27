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
    Casilla* casillas[36];
    
public:
    Board();
    Board(char *path);
    void setBoard(char* path);
};

#endif
