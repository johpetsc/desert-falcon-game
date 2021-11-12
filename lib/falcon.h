#ifndef FALCON_H_INCLUDED
#define FALCOM_H_INCLUDED

#include "SDL.h"
#include "SDL_image.h"
#include <stdbool.h>
#include <stdio.h>

SDL_Texture* createFalcon(int x, int y, SDL_Renderer* renderer, int height);
void destroyFalcon();
bool checkColision(SDL_Texture* falcon, SDL_Texture* object, int x, int y,int* j,int * k);

#endif