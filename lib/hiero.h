#ifndef HIERO_H_INCLUDED
#define HIERO_H_INCLUDED

#include "SDL.h"
#include "SDL_image.h"

SDL_Texture* createHiero(int* x, int* y, SDL_Renderer* renderer);
void destroyHiero();
#endif