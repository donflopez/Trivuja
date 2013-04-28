//
//  Board.cpp
//  Trivuja
//
//  Created by Francisco López Liébana on 22/04/13.
//  Copyright (c) 2013 Francisco López Liébana. All rights reserved.
//

#include "Board.h"

Board::Board(){
    CFrame brd;
    const char *path= "/Users/donflopez/Downloads/board.bmp";
    brd.load(path);
    this->addFrame(brd);
    this->setx(0);
    this->sety(0);
}

Board::Board(char *path){
    CFrame brd;
    brd.load(path);
    this->addFrame(brd);
    this->setx(0);
    this->sety(0);

}

void Board::setBoard(char *path){
    CFrame board;
    board.load(path);
}

