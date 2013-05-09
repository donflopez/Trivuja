//
//  Dice.cpp
//  Trivuja
//
//  Created by Francisco López Liébana on 09/05/13.
//  Copyright (c) 2013 Francisco López Liébana. All rights reserved.
//

#include "Dice.h"
#include <time.h>
#include <iostream>

int Dice::pull(){
    srand((unsigned int)time(NULL));
    return actual=rand()%6;
}