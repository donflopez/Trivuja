//
//  CSprite.h
//  Trivuja
//
//  Created by Francisco López Liébana on 08/04/13.
//  Copyright (c) 2013 Francisco López Liébana. All rights reserved.
//

#ifndef __Trivuja__CSprite__
#define __Trivuja__CSprite__

#include <SDL/SDL.h>

class CFrame {
public:
    SDL_Surface *img;
    void load(char *path);
    void unload();
};

class CSprite {
private:
    int xpos, ypos;
    int frame;
    int nFrames;
    int count;
    
public:
    CFrame *sprite;
    CSprite(int nFrames);
    CSprite();
    void finalize();
    void addFrame(CFrame frame);
    void selFrame(int nFrame);
    int frames(){return count;}
    void setx(int x) {xpos=x;}
    void sety(int y) {ypos=y;}
    void addx(int c) {xpos+=c;}
    void addy(int c) {ypos+=c;}
    int getx() {return xpos;}
    int gety() {return ypos;}
    int getw() {return sprite[frame].img->w;}
    int geth() {return sprite[frame].img->h;}
    void draw(SDL_Surface *superficie);
    int colision(CSprite sp);
    void delLatest(SDL_Surface *superfice);
};

#endif /* defined(__Trivuja__CSprite__) */
