#include<SDL/SDL.h>
#include"janela.h"
#include"Falcon.h"

void construtor(int x, int y){
	SDL_Surface* screen;

	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_WM_SetCaption("Jogo", "jogo");

	screen = SDL_SetVideoMode(x, y, 16, SDL_SWSURFACE);

	update(screen);
}

void update(SDL_Surface* screen){
	int j=0, x = 50, y = 49, altura = 1;;
	SDL_Event event;

	while(event.type != SDL_QUIT){
		SDL_PollEvent(&event);
		render(x, y, j, screen);

		switch(event.type){
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym){
                    case SDLK_LEFT:
                    	if((x > 50) && (y > 30)){
                        	x -= 2;
                        	y -= 2;
                        }
                        break;
                    case SDLK_RIGHT:
                    	if((x < 630) && (y < 330)){
                        	x += 2;
                        	y += 2;
                        }
                        break;
                    case SDLK_UP:
                    	if((altura < 2) && (y > 10)){
                        	y -= 15;
                        	altura++;
                    	}
                        break;
                    case SDLK_DOWN:
                    	if((altura > 0) && (y < 330)){
                        	y += 15;
                        	altura--;
                        }
                        break;
                    default:
                        break;
            }
        }
        

		if(j<340){
			j++;
		}else{
			j = 0;
		}
		SDL_Flip(screen);
	}
	destrutor();
}

void render(int x, int y, int j, SDL_Surface* screen){
	SDL_Rect drect = {50, 10, 540, 350};
	SDL_Rect drect2 = {x, y, 30, 30};
	SDL_Rect drect3 = {(530-j), (10+j), 20, 10};
	SDL_FillRect(screen, &drect, SDL_MapRGB(screen->format, 255, 180, 0));
	SDL_FillRect(screen, &drect2, SDL_MapRGB(screen->format, 100, 51, 23));
	SDL_FillRect(screen, &drect3, SDL_MapRGB(screen->format, 255, 255, 255));
	ConstroiFalcon();

}

void destrutor(){
	SDL_Quit();
}