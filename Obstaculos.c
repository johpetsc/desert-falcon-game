#include "Obstaculos.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

SDL_Texture* ConstroiObstaculos(int* j, int* l, SDL_Renderer* renderer){
	int k=*j,m=*l;
	SDL_Rect Obs = {(m), (k), 64, 64};
	IMG_Init(IMG_INIT_PNG);
	SDL_Surface* Obstaculos = IMG_Load("obstaculos.png"); 
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, Obstaculos);
	SDL_RenderCopy(renderer, texture, NULL, &Obs);

}
void DestroiObstaculos(SDL_Texture* Obstaculos){
	SDL_DestroyTexture(Obstaculos);
}