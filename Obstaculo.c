#include "Obstaculo.h"
#include "SDL.h"
#include "SDL_image.h"

SDL_Texture* ConstroiObstaculo(int* j, int* l, SDL_Renderer* renderer){
	int k=*j,m=*l;
	SDL_Rect Obs = {(m), (k), 64, 64};
	IMG_Init(IMG_INIT_PNG);
	SDL_Surface* Obstaculo = IMG_Load("obstaculo.png"); 
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, Obstaculo);
    SDL_RenderCopy(renderer, texture, NULL, &Obs);
    
    return texture;

}
void DestroiObstaculo(SDL_Texture* Obstaculo){
	SDL_DestroyTexture(Obstaculo);
}