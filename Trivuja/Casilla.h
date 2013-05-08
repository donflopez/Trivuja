//
//  Casilla.h
//  Trivuja
//
//  Created by Francisco López Liébana on 15/04/13.
//  Copyright (c) 2013 Francisco López Liébana. All rights reserved.
//

#include "CSprite.h"

#ifndef Trivuja_Casilla_h
#define Trivuja_Casilla_h

class Casilla {
private:
    Uint32 color[2];
    SDL_PixelFormat* format;
    SDL_Rect rect;
    int type;
    int selected;
public:
    Casilla(int type, const SDL_PixelFormat* format, int x, int y);
    int getType(){return type;};
    bool isSelected(){return selected>0;};
    void select(){selected=1;};
    void deselect(){selected=0;};
    void draw(SDL_Surface *screen);
};

#endif
