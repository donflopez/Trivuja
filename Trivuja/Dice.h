//
//  Dice.h
//  Trivuja
//
//  Created by Francisco López Liébana on 09/05/13.
//  Copyright (c) 2013 Francisco López Liébana. All rights reserved.
//

#ifndef Trivuja_Dice_h
#define Trivuja_Dice_h

class Dice {
    int actual;
    
public:
    Dice():actual(-1){};
    int pull();
    int getActual(){return actual;};
};

#endif
