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

class Casilla: public CSprite {
private:
    int type;
    bool selected;
public:
    Casilla(int type, bool selected, char* path);
    Casilla(int type, bool selected);
    void setType(int type);
};

#endif
