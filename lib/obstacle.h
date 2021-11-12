#ifndef OBSTACULO_H_INCLUDED
#define OBSTACULO_H_INCLUDED

#include "SDL.h"
#include "SDL_image.h"

SDL_Texture* createObstacle(int* x, int* y, SDL_Renderer* renderer);
void destroyObstacle();
#endif