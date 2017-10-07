#include "Hiero.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

void ConstroiHiero(int j, SDL_Renderer* renderer){
	SDL_Rect Hie = {(530-j), (10+j), 32, 32};
	IMG_Init(IMG_INIT_PNG);
	SDL_Surface* Hiero = IMG_Load("hiero.png"); // Inicia Falcon como NULL pois este é um ponteiro.
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, Hiero);
	SDL_RenderCopy(renderer, texture, NULL, &Hie);

	if(Hiero == NULL)
	printf( "Unable to load image flacon.png ! SDL_image Error: %s\n", IMG_GetError() );
	}