#include<SDL/SDL.h>
#include"janela.h"

SDL_Surface* screen;

void iniciaJanela(int x, int y){	

	SDL_Init(SDL_INIT_VIDEO);
	SDL_WM_SetCaption("Jogo", "jogo");

	screen = SDL_SetVideoMode(x, y, 16, SDL_SWSURFACE);
}

void atualizaJanela(){
	int sair = 0;
	int i=0;
	SDL_Event event;
	SDL_Rect drect = {50, 10, 540, 350};

	while(!sair){
		while(SDL_PollEvent(&event)){
			if(event.type == SDL_QUIT){
				sair = 1;
			}
		}
		SDL_Rect drect2 = {(50+i), (10+i), 10, 10};
		SDL_FillRect(screen, &drect2, SDL_MapRGB(screen->format, 0, 0, 255));
		SDL_Flip(screen);
		SDL_FillRect(screen, &drect, SDL_MapRGB(screen->format, 255, 180, 0));
		if(i<340){
			i++;
		}else{
			i = 0;
		}
	}
}

void fechaJanela(){
	SDL_Quit();
}