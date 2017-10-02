#include<SDL/SDL.h>
#include"janela.h"

#define SCREEN_W 640
#define SCREEN_H 480

int iniciaJanela(){

	SDL_Surface* screen;
	SDL_Event event;
	int sair = 0;	

	SDL_Init(SDL_INIT_VIDEO);
	SDL_WM_SetCaption("Jogo", "jogo");

	screen = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 16, SDL_SWSURFACE);
	SDL_Rect drect = {50, 10, 540, 350};
	SDL_FillRect(screen, &drect, SDL_MapRGB(screen->format, 255, 180, 0));
	
	while(!sair){
		while(SDL_PollEvent(&event)){
			if(event.type == SDL_QUIT){
				sair = 1;
			}
		}
		SDL_Flip(screen);
	}
	SDL_Quit();

	return 0;
}