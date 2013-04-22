//
//  Board.cpp
//  Trivuja
//
//  Created by Francisco López Liébana on 22/04/13.
//  Copyright (c) 2013 Francisco López Liébana. All rights reserved.
//

#include <iostream>
#include "Board.h"

Board::Board(){
    CFrame brd;
    brd.load("/Users/donflopez/Downloads/board.bmp");
    this->addFrame(brd);
    this->setx(0);
    this->sety(0);
}

void Board::setBoard(char *path){
    CFrame board;
    board.load(path);
}

