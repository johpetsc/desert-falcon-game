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
	int x = 50, y = 49, altura = 1,k=0;
    int* j=&k;
	SDL_Event event;

	while(event.type != SDL_QUIT){
		SDL_PollEvent(&event);
		render(x, y, j, renderer);

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
                    	if((x < 630) && (y < 316)){
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
        

		if(k<336){
			k++;
		}else{
			k = 0;
		}
		SDL_Delay(5);
		SDL_RenderPresent(renderer);
	}
}

void render(int x, int y, int* j, SDL_Renderer* renderer){
	SDL_Rect drect = {50, 10, 540, 370};
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(renderer, &drect);
	

    SDL_Texture* Hiero = ConstroiHiero(j, renderer);
	
    SDL_Texture* Falcon = ConstroiFalcon(x, y, renderer);
    if (ChecaColisao(Falcon, Hiero,x,y,j)== true){
        printf("destroi\n");
        *j=0;
        DestroiHiero(Hiero);
    }
}

void destrutor(SDL_Window* window, SDL_Renderer* renderer){
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}