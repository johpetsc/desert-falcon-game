#ifndef INIMIGO_H_INCLUDED
#define INIMIGO_H_INCLUDED

#include "SDL.h"
#include "SDL_image.h"

SDL_Texture* createEnemy(int* x, int* y, SDL_Renderer* renderer, int height);
void destroyEnemy(SDL_Texture* enemy);
#endif