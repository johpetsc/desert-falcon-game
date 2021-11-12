#include"SDL.h"/** SDL library for game development.*/
#include"SDL_ttf.h"/** SDL library for the text font.*/
#include"SDL_image.h"/** SDL library for PNG images.*/
#include"../lib/desert_falcon.h"
#include"../lib/falcon.h"
#include"../lib/hiero.h"
#include"../lib/obstacle.h"
#include"../lib/enemy.h"
#include"../lib/score.h"
#include<stdbool.h>

// constructor for the main game window
void constructor(int x, int y,int estado){
	int z, w, score = 0;
	
	SDL_Window* window; // main game window
	SDL_Renderer* renderer;
	SDL_Rect rectangle = {0, 0, x, y}; // main menu rectangle
	SDL_Event event; // mouse and keyboard event

	IMG_Init(IMG_INIT_PNG); 
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();

	// Loads menu images
	SDL_Surface* play_button = IMG_Load("assets/images/play.png");
	SDL_Surface* score_button = IMG_Load("assets/images/scoreboard.png");
	SDL_Surface* exit_button = IMG_Load("assets/images/exit.png");

	SDL_Rect play_rectangle = {200, 10,play_button->w,play_button->h};
	SDL_Rect score_rectangle = {200, 160,score_button->w,score_button->h};
	SDL_Rect exit_rectangle = {210, 310,exit_button->w,exit_button->h};
	SDL_Texture* play_texture; 
	SDL_Texture* score_texture;
	SDL_Texture* exit_texture;

	window = SDL_CreateWindow("Desert Falcon", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, x, y, 0);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(renderer, 192, 159, 45, 255);
	SDL_RenderClear(renderer);

	play_texture = SDL_CreateTextureFromSurface(renderer, play_button);
	score_texture = SDL_CreateTextureFromSurface(renderer, score_button);
	exit_texture = SDL_CreateTextureFromSurface(renderer, exit_button);

	SDL_RenderCopy(renderer, play_texture, NULL, &play_rectangle);
	SDL_RenderCopy(renderer, score_texture, NULL, &score_rectangle);
	SDL_RenderCopy(renderer, exit_texture, NULL, &exit_rectangle);

	SDL_RenderPresent(renderer);
	SDL_FreeSurface(play_button);
	SDL_FreeSurface(score_button);
	SDL_FreeSurface(exit_button);
	
	// user input loop	
	while(SDL_WaitEvent(&event)){

       	switch(event.type){
            case SDL_QUIT:
				SDL_DestroyTexture(play_texture);
				SDL_DestroyTexture(score_texture);
				SDL_DestroyTexture(exit_texture);
                destructor(window, renderer);
                break;
            case SDL_MOUSEBUTTONDOWN:
				z = event.button.x;
				w = event.button.y;
				if((z > 225) && (z < 417) && (w > 10) && (w < 160)){
					SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
					SDL_RenderClear(renderer);
					score = update(window,renderer);
					readPlayerName(score,window,renderer);
					SDL_SetRenderDrawColor(renderer, 192, 159, 45, 255);
					SDL_RenderClear(renderer);
					SDL_RenderCopy(renderer, play_texture, NULL, &play_rectangle);
					SDL_RenderCopy(renderer, score_texture, NULL, &score_rectangle);
					SDL_RenderCopy(renderer, exit_texture, NULL, &exit_rectangle);
					SDL_RenderPresent(renderer);
				}
				if((z > 225) && (z < 370) && (w > 325) && (w < 410)){
					SDL_DestroyTexture(play_texture);
					SDL_DestroyTexture(score_texture);
					SDL_DestroyTexture(exit_texture);
					destructor(window, renderer);
				}
				break;
					
		}
	}

	destructor(window, renderer);
}

// updates the game
int update(SDL_Window* window,SDL_Renderer* renderer){
	int alt=0 ,x = 50, y = 49, y1 = 49, height = 1, k = -10, m = 0, k1 = -20, m1 = 0, k2 = -20, m2 = 0, flag = 0, flag1 = 0, flag2 = 0,flag3 =0;
	int score = 0, temp, running = 1;
	char scores[12];
	char aux[8];
	int* j = &k;
	int* j1 = &k1;
	int* j2 = &k2;
	int* l = &m;
	int* l1 = &m1;
	int* l2 = &m2;
	
	SDL_Color yellow = {203,211,0};
	SDL_Surface* surfScore;
	SDL_Texture* textScore;
	SDL_Rect posScore = {40,430 , 0, 0};
	SDL_Event event;
	TTF_Font* sans = TTF_OpenFont("assets/font/Sans.ttf", 24);
	
	while(event.type!= SDL_QUIT){
		SDL_PollEvent(&event);
        if (flag == 0){
			m = (rand() % 640) + 360;
		}
		if (flag1 == 0){
			m1 = (rand() % 640) + 60;
		}
		if (flag2 ==  0){
			m2 = (rand() % 640) + 160;
		}
		if (flag3 == 0){
			alt = (rand() % 3);
		}
		temp = render(alt, x, y, y1, j, l, j1, l1, j2, l2, height, renderer);
		if (temp == 10){
			SDL_DestroyTexture(textScore);
			SDL_FreeSurface(surfScore);
			return score;

		}
		score  = score + temp;

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderFillRect(renderer,&posScore);
		strcpy(scores,  "SCORE: ");
		sprintf(aux, "%d", score);
		strcat(scores, aux);
		surfScore = TTF_RenderText_Solid(sans, scores, yellow);
		textScore = SDL_CreateTextureFromSurface(renderer, surfScore);
		posScore.w = surfScore->w;
		posScore.h = surfScore->h;
		SDL_RenderCopy(renderer, textScore, NULL, &posScore);
		SDL_RenderPresent(renderer);
		SDL_DestroyTexture(textScore);
		SDL_Delay(5);
		flag = 1;
		flag1 = 1;
		flag2 = 1;
		flag3 = 1;
		switch(event.type){
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym){
                    case SDLK_LEFT:
                    	if((x > 0) && (y > 0)){
                        	x -= 2;
							y -= 2;
							y1 -= 2;
                        }
                        break;
                    case SDLK_RIGHT:
                    	if((x < 630) && (y < 320)){
                        	x += 2;
							y += 2;
							y1 += 2;
                        }
                        break;
                    case SDLK_UP:
                    	if((height < 2) && (y > 10)){
                        	y -= 15;
                        	height++;
                    	}
                        break;
                    case SDLK_DOWN:
                    	if((height > 0) && (y < 316)){
                        	y += 15;
                        	height--;
                        }
                        break;
                    default:
                        break;
            }
        }
		if((k2 < 325) && (m2 < 550)){
			k2 = k2 + 2; 
			m2 = m2 - 2;
		}else{
			k2 = -20;
			m2 = 0;
			flag2 = 0;
			flag3 = 0;
		}
		
		if((k1 < 325) && (m1 < 550)){
			k1++, m1--;
		}else{
			k1 = -20, m1 = 0,flag1 = 0;
		}

		if((k < 350) && (m < 550)){
			k++, m--;
		}else{
			k = -20, m = 0,flag = 0;
		}

		SDL_Delay(5);
	}
	
	destructor(window, renderer);
}

// renders the game components
int render(int alt, int x, int y, int y1, int* j, int* l, int* j1, int* l1 ,int* j2, int* l2, int height, SDL_Renderer* renderer){
	int score = 0;
	SDL_Rect rectangle = {0, 0, 640, 380};
	SDL_SetRenderDrawColor(renderer, 255, 255, 140, 255);
	SDL_RenderFillRect(renderer, &rectangle);
	
	SDL_Texture* hiero = createHiero(j,l, renderer);
	SDL_Texture* obstacle = createObstacle(j1, l1, renderer);
	SDL_Texture* enemy = createEnemy( j2, l2, renderer, alt);
    SDL_Texture* falcon = createFalcon(x, y, renderer, height);
	if(height>=alt){
		SDL_Texture* enemy = createEnemy( j2, l2, renderer, alt);
    	SDL_Texture* falcon = createFalcon(x, y, renderer, height);
	}else{
		SDL_Texture* falcon = createFalcon(x, y, renderer, height);
		SDL_Texture* enemy = createEnemy( j2, l2, renderer, alt);
	}
	
		
    if ((checkColision(falcon, hiero, x, y, j,l)== true) && height==0){
		*j=0;
		*l = (rand() % 640) + 360;
		score += 1;
        destroyHiero(hiero);
    }
	else if((checkColision(falcon, obstacle, x, y, j1,l1)== true) && height==0){
		destroyObstacle(obstacle); 
		destroyFalcon(falcon);
		return 10;

	}
	else if((checkColision(falcon, enemy, x, y, j2,l2)== true) && height==alt){
		destroyObstacle(enemy); 
		destroyFalcon(falcon);
		return 10;

	}
	return score;
}

// destrois the game window
void destructor(SDL_Window* window, SDL_Renderer* renderer){

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}