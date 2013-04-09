//
//  CSprite.cpp
//  Trivuja
//
//  Created by Francisco López Liébana on 08/04/13.
//  Copyright (c) 2013 Francisco López Liébana. All rights reserved.
//

#include <SDL/SDL.h>
#include "CSprite.h"

void CFrame::load(char *path) {
    img=SDL_LoadBMP(path);
    // Asignamos el color transparente al color rojo.
    SDL_SetColorKey(img,SDL_SRCCOLORKEY|SDL_RLEACCEL, SDL_MapRGB(img->format,255,0,0));
    img=SDL_DisplayFormat(img);
}

void CFrame::unload(){
    SDL_FreeSurface(img);
}

CSprite::CSprite(int nf) {
    sprite=new CFrame[nf];
    nFrames=nf;
    count=0;
}
CSprite::CSprite() {
    int nf=1;
    sprite=new CFrame[nf];
    nFrames=nf;
    count=0;
}
void CSprite::finalize() {
    int i;
    for (i=0 ; i<=nFrames-1 ; i++)
        sprite[i].unload();
}
void CSprite::addFrame(CFrame frame) {
    if (count<nFrames) {
        sprite[count]=frame;
        count++;
    }
}
void CSprite::selFrame(int nf) {
    if (nf<=nFrames) { 
        frame=nf; 
    } 
}