 //
//  CSprite.cpp
//  Trivuja
//
//  Created by Francisco López Liébana on 08/04/13.
//  Copyright (c) 2013 Francisco López Liébana. All rights reserved.
//

#include <SDL/SDL.h>
#include "CSprite.h"

/**@brief:Carga una superficie
 * @param:puntero de tipo char(ruta de busqueda de una imagen en bmp)
 * @pre:
 * @post:
 */
void CFrame::load(const char *path) {
    SDL_Surface *image;
    image = SDL_LoadBMP(path);
    // Asignamos el color transparente al color rojo.
    SDL_SetColorKey(image,SDL_SRCCOLORKEY|SDL_RLEACCEL, SDL_MapRGB(image->format,255,0,0));
    img=SDL_DisplayFormat(image);
    SDL_FreeSurface(image);
}

/**@brief:libera una superficie del atributo img
 * @param:ninguno
 * @pre:ninguno
 * @post:ninguno
        
 */
void CFrame::unload(){
    SDL_FreeSurface(img);
}

/**@brief:constructor que crea nf frames
 * @param:el numero de frames nf(int)
 * @pre:ninguno
 * @post:ninguno
 
 */
CSprite::CSprite(int nf) {
    sprite=new CFrame[nf];
    nFrames=nf;
    frame=0;
    count=0;
}

/**@brief:constuctor por defecto de CSprite*/
CSprite::CSprite() {
    int nf=1;
    sprite=new CFrame[nf];
    nFrames=nf;
    frame=0;
    count=0;
}

/**@brief:función que finaliza un sprite,es decir,elimina todos los frames de un sprite)
 * @param:ninguno:
 * @pre:ninguno
 * @post:ninguno
 
 */
void CSprite::finalize() {
    int i;
    for (i=0 ; i<=nFrames-1 ; i++)
        sprite[i].unload();
}

/**@brief:añade un frame a un sprite
 * @param:objeto de tipo frame
 * @pre:ninguno
 * @post:ninguno
 */
void CSprite::addFrame(CFrame frame) {
    if (count<nFrames) {
        sprite[count]=frame;
        count++;
    }
}

/**@brief:selecciona  un frame de un sprite
 * @param:el numero de frame seleccionado(int)
 * @pre:ninguno
 * @post:ninguno
 */
void CSprite::selFrame(int nf) {
    if (nf<=nFrames) { 
        frame=nf; 
    } 
}

/**@brief:elimina una superficie(pone en negro dicha superficie)
 * @param:un puntero a una superficie(SDL_Surface*)
 * @pre:ninguno
 * @post:niguno
 
 */
void CSprite::delLatest(SDL_Surface *surface) {
    SDL_Rect rect;
    rect.x=this->getx();
    rect.y=this->gety();
    rect.h=this->geth();
    rect.w=this->getw();
    SDL_FillRect(surface, &rect, SDL_MapRGB(surface->format,0,0,0));
}

/**@brief:dibuja una superficie,es decir vuelca los graficos en pantalla a traves
 de la funcion de SDL BlitSurface
 * @param:un puntero de superficie que quermos dibujar(SDL_Surface*)
 * @pre:ninguno
 * @post:ninguno
 */

void CSprite::draw(SDL_Surface *superficie) { 
    SDL_Rect dest;
    dest.x=xpos; 
    dest.y=ypos;
    SDL_BlitSurface(sprite[frame].img,NULL,superficie,&dest);
} 
