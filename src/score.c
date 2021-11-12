#include "../lib/score.h"

// reads the player name for the scoreboard after the game is finished
int readPlayerName(int score, SDL_Window* window, SDL_Renderer* renderer){
    int name_length;
    SDL_Rect box;
    char name[10] = "NAME : ";
    SDL_Event event;
    TTF_Font* sans = TTF_OpenFont("assets/font/Sans.ttf", 24);
    SDL_Color blue = {0,119,212};
    SDL_Surface* surfScore;
	SDL_Texture* textScore;
    
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,"End of the game",
								"You died, type 3 characters to enter the scoreboard.",NULL);
    
    SDL_StartTextInput();
    while(SDL_WaitEvent(&event) != 0){
        name_length = strlen(name);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	    SDL_RenderClear(renderer);
        if(event.type == SDL_QUIT){
            destructor(window,renderer);
            break;
        }
        else if(event.type == SDL_TEXTINPUT || event.type == SDL_KEYDOWN){
            if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_BACKSPACE && (strlen(name) > 7)){
                name[name_length-1] = '\0';
                name_length = name_length - 1;
            }
            else if(event.type == SDL_TEXTINPUT && name_length < 10){
                strcat(name, event.text.text);
                name_length = name_length + 1;
            }
            else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RETURN && (strlen(name) > 7)){
                writeScoreboard(score, name);
                return 0;
            }
        }
        box.x = 220;
        box.y = 220;
		box.w = surfScore->w;
		box.h = surfScore->h;
        surfScore = TTF_RenderText_Solid(sans, name, blue);
		textScore = SDL_CreateTextureFromSurface(renderer, surfScore);
        SDL_FreeSurface(surfScore);
		SDL_RenderCopy(renderer, textScore, NULL, &box);
		SDL_RenderPresent(renderer);
		SDL_DestroyTexture(textScore);
    }  
}

// writes the player score on the scoreboard
void writeScoreboard(int scores, char* name){
    char player_score[7] = "";
    int i = 0;

    sprintf(player_score, "%d", scores);
       
    for(i = 1; i < 4; i++){
        player_score[i] = name[i+6];
    }        
    
    FILE *fp = fopen ("assets/text/scoreboard.txt", "r+");

    fseek(fp, 0, SEEK_END) ;
    fputs(player_score, fp);
    fputs("\n", fp); 
    
    fclose(fp);
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "SCORE",
								"You have been placed on the scoreboard.", NULL);
}