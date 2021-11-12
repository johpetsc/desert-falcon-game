#include "../lib/obstacle.h"

// creates and renders an obstacle
SDL_Texture* createObstacle(int* x, int* y, SDL_Renderer* renderer){
	int pos_y = *y, pos_x = *x;
	SDL_Rect rectangle = {(pos_y), (pos_x), 64, 64};
	IMG_Init(IMG_INIT_PNG);
	SDL_Surface* obstacle = IMG_Load("assets/images/obstacle.png"); // loads obstacle image file
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, obstacle); // creates texture for the obstacle
    SDL_RenderCopy(renderer, texture, NULL, &rectangle); // renders the obstacle
    
    return texture;

}

// destrois an obstacle
void destroyObstacle(SDL_Texture* obstacle){

	SDL_DestroyTexture(obstacle);
}