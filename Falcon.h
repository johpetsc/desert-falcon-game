/* Arquivo header do módulo falcon.*/

#ifndef FALCON_H_INCLUDED
#define FALCOM_H_INCLUDED

#include "SDL.h"
#include "SDL_image.h"
#include <stdbool.h>

SDL_Texture* ConstroiFalcon();
void DestroiFalcon();
bool ChecaColisao();

#endif