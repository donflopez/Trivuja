//
//  Board.cpp
//  Trivuja
//
//  Created by Francisco López Liébana on 22/04/13.
//  Copyright (c) 2013 Francisco López Liébana. All rights reserved.
//

#include "Board.h"

Board::Board(const SDL_PixelFormat* format){
    const char *path= "/Users/donflopez/Downloads/board.bmp";
    brd.load(path);
    this->addFrame(brd);
    this->setx(0);
    this->sety(0);
    int type = 0;
    int xPixelsAux = 0, yPixelsAux = 0;
    for (int i=0; i<36; i++) {
        if(type<6){
            if (i<12) {
                casillas[i]= new Casilla(type,format,4+53*i,3);
                xPixelsAux = 4+53*i;
            }
            else {
                if (i<19) {
                    casillas[i]= new Casilla(type,format,xPixelsAux,3+53*(i-11));
                    yPixelsAux = 3+53*(i-11);
                }
                else {
                    if(i<30){
                        casillas[i]= new Casilla(type,format,xPixelsAux-53*(i-18),yPixelsAux);
                    }
                    else {
                        casillas[i]= new Casilla(type,format, 3,yPixelsAux-53*(i-29));
                    }
                }
            }
            type++;
        }
        else {
            type=0;
            if (i<12) {
                casillas[i]= new Casilla(type,format,4+53*i,3);
                xPixelsAux = 4+53*i;
            }
            else {
                if (i<19) {
                    casillas[i]= new Casilla(type,format,xPixelsAux,3+53*(i-11));
                    yPixelsAux = 3+53*(i-11);
                }
                else {
                    if(i<30){
                        casillas[i]= new Casilla(type,format,xPixelsAux-53*(i-18),yPixelsAux);
                    }
                    else {
                        casillas[i]= new Casilla(type,format, 3,yPixelsAux-53*(i-29));
                    }
                }
            }

            type++;
        }
    }
    casillas[0]->select();
}

Board::Board(char *path, const SDL_PixelFormat* format){
    brd.load(path);
    this->addFrame(brd);
    this->setx(0);
    this->sety(0);
    for (int i=0; i<36; i++) {
        casillas[i]= new Casilla(0,format,4+51*i,3);
    }
}

void Board::setBoard(char *path){
    brd.load(path);
}

void Board::drawCasillas(SDL_Surface *screen){
    for (int i=0; i<36; i++) {
        casillas[i]->draw(screen);
    }
}

int Board::selectCasilla(int number, SDL_Surface *screen){
    int actual=0;
    for (int i=0; i<36; i++) {
        if(casillas[i]->isSelected()&&actual+number>i){
            if(actual==0)
                actual=i;
            casillas[i]->deselect();
            this->drawCasillas(screen);
            SDL_Flip(screen);
            casillas[i+1]->select();
        }
        this->drawCasillas(screen);
        SDL_Flip(screen);
    }
    return casillas[actual+number]->getType();
}

