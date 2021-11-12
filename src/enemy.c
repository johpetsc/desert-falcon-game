#include "../lib/enemy.h"

// creates and renders an enemy
SDL_Texture* createEnemy(int* x, int* y, SDL_Renderer* renderer, int height){
	int pos_y = *y, pos_x = *x;
	SDL_Rect rectangle = {(pos_y), (pos_x), 48, 48};
	SDL_Rect shadow_rectangle = {pos_y, (pos_x+(height*15)), 48, 48}; // enemy shadow position
	IMG_Init(IMG_INIT_PNG);
	SDL_Surface* enemy = IMG_Load("assets/images/enemy.png"); // loads enemy image file
	SDL_Surface* shadow = IMG_Load("assets/images/enemy_shadow.png"); // loads shadow image file
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, enemy); // creates texture for the enemy
	SDL_Texture* shadow_texture = SDL_CreateTextureFromSurface(renderer, shadow); // creates shadow texture
	SDL_RenderCopy(renderer, shadow_texture, NULL, &shadow_rectangle); // renders enemy shadow
	SDL_RenderCopy(renderer, texture, NULL, &rectangle); // renders the enemy

    return texture;
}

// destrois an obstacle
void destroyEnemy(SDL_Texture* enemy){

	SDL_DestroyTexture(enemy);
}