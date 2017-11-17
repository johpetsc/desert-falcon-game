#include "Falcon.h"
#include "SDL.h"
#include "SDL_image.h"
#include <stdbool.h>
#include <stdio.h>

SDL_Texture* ConstroiFalcon(int x, int y, SDL_Renderer* renderer, int altura){
/** Função para construção do componente falcon.*/

	SDL_Rect Fal = {x, y, 64, 64};
	SDL_Rect Som = {x, (y+10+(altura*15)), 64, 64};/** Posição da sombra do falcon.*/
	IMG_Init(IMG_INIT_PNG);
	SDL_Surface* Falcon = IMG_Load("falcon.png"); /** Carrega a imagem do falcon.*/
	SDL_Surface* Sombra = IMG_Load("sombra.png"); /** Carrega a imagem da sombra do falcon.*/
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, Falcon); /** Cria a textura do falcon.*/
	SDL_Texture* texture2 = SDL_CreateTextureFromSurface(renderer, Sombra); /** Cria a textura da sombra do falcon.*/
	SDL_RenderCopy(renderer, texture2, NULL, &Som); /** Renderiza o falcon.*/
	SDL_RenderCopy(renderer, texture, NULL, &Fal); /** Renderiza a sombra do falcon.*/

	return texture;
}


void DestroiFalcon(SDL_Texture* Falcon){
/** Função para destruir o componente falcon.*/

	SDL_DestroyTexture(Falcon);
}

bool ChecaColisao(SDL_Texture* Objeto1, SDL_Texture* Objeto2,int x, int y,int* j,int * k){
/** Função para checar se há colisão entre o falcon e outros componentes do jogo.*/

	int esquerda1, esquerda2, direita1, direita2, cima1, cima2, abaixo1, abaixo2;
	int largura1, largura2, altura1, altura2;
	SDL_QueryTexture(Objeto1, NULL, NULL, &largura1, &altura1);
	SDL_QueryTexture(Objeto2, NULL, NULL, &largura2, &altura2);

	SDL_Rect Rect1, Rect2;

    Rect1.x = x;
    Rect1.y = y;
    Rect1.w = largura1;
    Rect1.h = altura1;
    Rect2.x = *k;
    Rect2.y = *j;
    Rect2.w = largura2;
    Rect2.h = altura2;

    esquerda1 = Rect1.x;
    cima1 = Rect1.y;
	direita1 = Rect1.x + Rect1.w+30;
	abaixo1 = Rect1.y + Rect1.h; 
	esquerda2 = Rect2.x;
	cima2 = Rect2.y;
	direita2 = Rect2.x + Rect2.w;
	abaixo2 = Rect2.y + Rect2.h; 
	
	if( abaixo1 < cima2 ) 
		return false; 
	else if( cima1 > abaixo2 ) 
		return false; 
	else if( direita1 < esquerda2 ) 
	 	return false; 
	else if( esquerda1 > direita2 ) 
	 	return false; 
	else return true;
}