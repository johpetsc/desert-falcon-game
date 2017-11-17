#include "Inimigo.h"
#include "SDL.h"
#include "SDL_image.h"

SDL_Texture* ConstroiInimigo(int* j, int* l, SDL_Renderer* renderer){
/** Função para contrução do componente inimigo.*/

	int k = *j,m = *l;
	SDL_Rect Ini = {(m), (k), 48, 48};
	IMG_Init(IMG_INIT_PNG);
	SDL_Surface* Inimigo = IMG_Load("Imagens/inimigo.png"); /** Carrega a imagem do inimigo.*/
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, Inimigo); /** Cria a textura do inimigo.*/
    SDL_RenderCopy(renderer, texture, NULL, &Ini); /** Renderiza o inimigo.*/
    
    return texture;
}

void DestroiInimigo(SDL_Texture* Inimigo){
/** Função para destruir o componente inimigo.*/

	SDL_DestroyTexture(Inimigo);
}