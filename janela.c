#include<SDL2/SDL.h>
#include"janela.h"
#include"Falcon.h"
#include"Hiero.h"
#include<stdbool.h>

void construtor(int x, int y){
	SDL_Window* window;
	SDL_Renderer* renderer;

	SDL_Init(SDL_INIT_EVERYTHING);

	window = SDL_CreateWindow("Jogo", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, x, y, 0);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	update(renderer);
	destrutor(window, renderer);
}

void update(SDL_Renderer* renderer){
	int x = 50, y = 49, altura = 1, k = 0, m = 0, flag = 0;
    int* j = &k;
    int* l = &m;
	SDL_Event event;

	while(event.type != SDL_QUIT){
		SDL_PollEvent(&event);
        if (flag == 0){
            m = (rand() % 640) + 360;
        }
		render(x, y, j, l, altura, renderer);
        flag = 1;
		switch(event.type){
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym){
                    case SDLK_LEFT:
                    	if((x > 0) && (y > 0)){
                        	x -= 2;
                        	y -= 2;
                        }
                        break;
                    case SDLK_RIGHT:
                    	if((x < 630) && (y < 320)){
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
                    	if((altura > 0) && (y < 316)){
                        	y += 15;
                        	altura--;
                        }
                        break;
                    default:
                        break;
            }
        }
        

		if((k < 342) && (m < 550)){
			k++, m--;
		}else{
			k = 0,m = 0,flag = 0;
		}

		SDL_Delay(5);
		SDL_RenderPresent(renderer);
	}
}

void render(int x, int y, int* j, int* l, int altura, SDL_Renderer* renderer){
	SDL_Rect drect = {0, 0, 680, 380};
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(renderer, &drect);
	

    SDL_Texture* Hiero = ConstroiHiero(j,l, renderer);
	
    SDL_Texture* Falcon = ConstroiFalcon(x, y, renderer);
    if ((ChecaColisao(Falcon, Hiero, x, y, j,l)== true) && altura==0){
		*j=0;
		*l = (rand() % 640) + 360;
        DestroiHiero(Hiero);
    }
}

void destrutor(SDL_Window* window, SDL_Renderer* renderer){
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}