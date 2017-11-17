#include "Hiero.h"
#include "SDL.h"
#include "SDL_image.h"

SDL_Texture* ConstroiHiero(int* j,int* l, SDL_Renderer* renderer){
/** Função para contrução do componente Hiero.*/

	int k = *j, m = *l;
	SDL_Rect Hie = {(m), (k), 32, 32};
	IMG_Init(IMG_INIT_PNG);
	SDL_Surface* Hiero = IMG_Load("hiero.png"); /** Carrega a imagem do hiero.*/
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, Hiero);/** Cria a textura do hiero.*/
	SDL_RenderCopy(renderer, texture, NULL, &Hie);/** Renderiza o hiero.*/

	
	return texture;
}

void DestroiHiero(SDL_Texture* Hiero){
/** Função para destruir o componente hiero.*/

	SDL_DestroyTexture(Hiero);
}
