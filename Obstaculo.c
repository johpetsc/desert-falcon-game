#include "Obstaculo.h"
#include "SDL.h"
#include "SDL_image.h"

SDL_Texture* ConstroiObstaculo(int* j, int* l, SDL_Renderer* renderer){
/** Função para construção do componente obstáculo.*/

	int k = *j, m = *l;
	SDL_Rect Obs = {(m), (k), 64, 64};
	IMG_Init(IMG_INIT_PNG);
	SDL_Surface* Obstaculo = IMG_Load("obstaculo.png"); /** Carrega a imagem do obstáculo.*/
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, Obstaculo);/** Cria a textura do obstáculo.*/
    SDL_RenderCopy(renderer, texture, NULL, &Obs);/** Renderiza o obstáculo.*/
    
    return texture;

}
void DestroiObstaculo(SDL_Texture* Obstaculo){
/** Função para destruir o componente obstáculo.*/

	SDL_DestroyTexture(Obstaculo);
}