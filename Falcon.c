#include "Falcon.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdbool.h>
#include <stdio.h>

SDL_Texture* ConstroiFalcon(int x, int y, SDL_Renderer* renderer){
	SDL_Rect Fal = {x, y, 64, 64};
	IMG_Init(IMG_INIT_PNG);
	SDL_Surface* Falcon = IMG_Load("falcon.png"); // Inicia Falcon como NULL pois este é um ponteiro.
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, Falcon);
	SDL_RenderCopy(renderer, texture, NULL, &Fal);

	if(Falcon == NULL)
	printf( "Unable to load image flacon.png ! SDL_image Error: %s\n", IMG_GetError() );
	return texture;
	}


void DestroiFalcon(SDL_Texture* Falcon){
	SDL_DestroyTexture(Falcon);
	printf("destroi/n");
}

bool ChecaColisao(SDL_Texture* Objeto1, SDL_Texture* Objeto2,int x, int y,int* j){
	int esquerda1, esquerda2, direita1, direita2, cima1, cima2, abaixo1, abaixo2;
	int largura1, largura2, altura1, altura2;
	SDL_QueryTexture(Objeto1, NULL, NULL, &largura1, &altura1);
	SDL_QueryTexture(Objeto2, NULL, NULL, &largura2, &altura2);

	SDL_Rect Rect1, Rect2;

    Rect1.x = x;
    Rect1.y = y;
    Rect1.w = largura1;
    Rect1.h = altura1;
    Rect2.x = (530-(*j));
    Rect2.y = (10+(*j));
    Rect2.w = largura2;
    Rect2.h = altura2;

    esquerda1 = Rect1.x;
    cima1 = Rect1.y;
	direita1 = Rect1.x + Rect1.w;
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