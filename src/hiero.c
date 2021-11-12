#include "../lib/hiero.h"

// creates and renders the a hieroglyph
SDL_Texture* createHiero(int* x, int* y, SDL_Renderer* renderer){
	int pos_y = *y, pos_x = *x;
	SDL_Rect rectangle = {(pos_y), (pos_x), 32, 32};
	IMG_Init(IMG_INIT_PNG);
	SDL_Surface* hiero = IMG_Load("assets/images/hiero.png"); // loads hiero image file
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, hiero); // creates texture for the hiero
	SDL_RenderCopy(renderer, texture, NULL, &rectangle); // renders the hiero

	
	return texture;
}

// destrois a hieroglyph
void destroyHiero(SDL_Texture* hiero){

	SDL_DestroyTexture(hiero);
}
