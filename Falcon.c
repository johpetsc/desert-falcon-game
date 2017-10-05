#include "Falcon.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

int ConstroiFalcon(){
	SDL_Surface* Falcon = NULL; // Inicia Falcon como NULL pois este é um ponteiro.
	int imgFlags = IMG_INIT_PNG; 
	int imginiciada=IMG_Init(imgFlags); // Inicializa a imagem.

	if((imginiciada & imgFlags) != imgFlags) { // Checa se a imagem foi inicializada com sucesso.
    printf("IMG_Init: Failed to init required png support!\n");
    printf("IMG_Init: %s\n", IMG_GetError());
    // handle error
	}

	Falcon=IMG_Load("falcon.png");
	if(Falcon == NULL)
		return 0;
	else
		return 1;
	}

void DestroiFalcon(SDL_Surface* Falcon){
	SDL_FreeSurface(Falcon);
}

