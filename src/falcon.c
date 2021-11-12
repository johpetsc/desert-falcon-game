#include "../lib/falcon.h"

// creates and renders the falcon
SDL_Texture* createFalcon(int x, int y, SDL_Renderer* renderer, int height){
	SDL_Rect falcon_rectangle = {x, y, 64, 64};
	SDL_Rect shadow_rectangle = {x, (y+10+(height*15)), 64, 64}; // falcon shadow position
	IMG_Init(IMG_INIT_PNG);
	SDL_Surface* falcon = IMG_Load("assets/images/falcon.png"); // loads falcon image file
	SDL_Surface* shadow = IMG_Load("assets/images/shadow.png"); // loads shadow image file
	SDL_Texture* falcon_texture = SDL_CreateTextureFromSurface(renderer, falcon); // creates falcon texture
	SDL_Texture* shadow_texture = SDL_CreateTextureFromSurface(renderer, shadow); // creates shadow texture
	SDL_RenderCopy(renderer, shadow_texture, NULL, &shadow_rectangle); // renders falcon shadow
	SDL_RenderCopy(renderer, falcon_texture, NULL, &falcon_rectangle); // renders falcon

	return falcon_texture;
}

// destrois the falcon
void destroyFalcon(SDL_Texture* falcon){

	SDL_DestroyTexture(falcon);
}

// checks if the falcon collided with an obstacle or an enemy
bool checkColision(SDL_Texture* falcon, SDL_Texture* object, int x, int y,int* j,int * k){
	int falcon_width, object_width, falcon_height, object_height;
	SDL_QueryTexture(falcon, NULL, NULL, &falcon_width, &falcon_height);
	SDL_QueryTexture(object, NULL, NULL, &object_width, &object_height);

	SDL_Rect falcon_rectangle, object_rectangle;

    falcon_rectangle.x = x;
    falcon_rectangle.y = y;
    falcon_rectangle.w = falcon_width;
    falcon_rectangle.h = falcon_height;
    object_rectangle.x = *k;
    object_rectangle.y = *j;
    object_rectangle.w = object_width;
    object_rectangle.h = object_height;
	
	if(falcon_rectangle.y + falcon_rectangle.h < object_rectangle.y) 
		return false; 
	else if(falcon_rectangle.y > object_rectangle.y + object_rectangle.h) 
		return false; 
	else if(falcon_rectangle.x + falcon_rectangle.w+30 < object_rectangle.x) 
	 	return false; 
	else if(falcon_rectangle.x > object_rectangle.x + object_rectangle.w) 
	 	return false; 
	else return true;
}