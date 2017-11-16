#include "Inimigo.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

SDL_Texture* ConstroiInimigo(int* j, int* l, SDL_Renderer* renderer){
	int k=*j,m=*l;
	SDL_Rect Ini = {(m), (k), 48, 48};
	IMG_Init(IMG_INIT_PNG);
	SDL_Surface* Inimigo = IMG_Load("inimigo.png"); 
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, Inimigo);
    SDL_RenderCopy(renderer, texture, NULL, &Ini);

    return texture;

}
void DestroiInimigo(SDL_Texture* Inimigo){
	SDL_DestroyTexture(Inimigo);
}