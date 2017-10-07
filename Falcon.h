#ifndef FALCON_H_INCLUDED
#define FALCOM_H_INCLUDED
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdbool.h>

SDL_Texture* ConstroiFalcon();
void DestroiFalcon();
bool ChecaColisao();

#endif