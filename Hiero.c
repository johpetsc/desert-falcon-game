#include "Hiero.h"
#include "SDL.h"
#include "SDL_image.h"

SDL_Texture* ConstroiHiero(int* j,int* l, SDL_Renderer* renderer){
	int k=*j,m=*l;
	SDL_Rect Hie = {(m), (k), 32, 32};
	IMG_Init(IMG_INIT_PNG);
	SDL_Surface* Hiero = IMG_Load("hiero.png"); 
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, Hiero);
	SDL_RenderCopy(renderer, texture, NULL, &Hie);

	
	return texture;
}

void DestroiHiero(SDL_Texture* Hiero){
	SDL_DestroyTexture(Hiero);
}
