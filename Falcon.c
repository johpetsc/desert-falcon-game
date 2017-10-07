#include "Falcon.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

void ConstroiFalcon(int x, int y, SDL_Renderer* renderer){
	SDL_Rect Fal = {x, y, 64, 64};
	IMG_Init(IMG_INIT_PNG);
	SDL_Surface* Falcon = IMG_Load("falcon.png"); // Inicia Falcon como NULL pois este é um ponteiro.
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, Falcon);
	SDL_RenderCopy(renderer, texture, NULL, &Fal);

	if(Falcon == NULL)
	printf( "Unable to load image flacon.png ! SDL_image Error: %s\n", IMG_GetError() );
	}

void DestroiFalcon(SDL_Surface* Falcon){
	SDL_FreeSurface(Falcon);
}

