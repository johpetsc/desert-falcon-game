#include "Escrita.h"
#include "janela.h"
#include "SDL.h"
#include "SDL_ttf.h"
#include <string.h>

int PegaNome(int ponto,SDL_Window* window,SDL_Renderer* renderer){
    int tamanho,i;
    SDL_Rect box ;
    char nome[10]="NOME : ";
    SDL_Event ev;
    TTF_Font* sans = TTF_OpenFont("Sans.ttf", 24);
    SDL_Color azul = {0,119,212};
    SDL_Surface* surfScore;
	SDL_Texture* textScore;
    
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,"Final do Jogo",
								"Você morreu, digite 3 caracteres para entrar no rank de pontuação.",NULL);
    
    SDL_StartTextInput();
    while(SDL_WaitEvent(&ev) != 0){
        tamanho = strlen(nome);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	    SDL_RenderClear(renderer);
        if(ev.type == SDL_QUIT){
            destrutor(window,renderer);
            break;
        }
        else if(ev.type == SDL_TEXTINPUT || ev.type == SDL_KEYDOWN){
            if(ev.type == SDL_KEYDOWN && ev.key.keysym.sym == SDLK_BACKSPACE && (strlen(nome) > 7)){
                
                nome[tamanho-1] = '\0';
                tamanho = tamanho - 1;
               
            }
            else if(ev.type == SDL_TEXTINPUT && tamanho < 10){
                
                strcat(nome, ev.text.text);
                tamanho = tamanho + 1;
            }
            else if (ev.type == SDL_KEYDOWN && ev.key.keysym.sym == SDLK_RETURN && (strlen(nome) > 7)){
                InsereNome(ponto,nome);
                return 0;
            }

        }
        box.x = 220;
        box.y = 220;
		box.w = surfScore->w;
		box.h = surfScore->h;
        surfScore = TTF_RenderText_Solid(sans, nome, azul);
		textScore = SDL_CreateTextureFromSurface(renderer, surfScore);
        SDL_FreeSurface(surfScore);
		SDL_RenderCopy(renderer, textScore, NULL, &box);
		SDL_RenderPresent(renderer);
		SDL_DestroyTexture(textScore);
    }  
}

void InsereNome(int pontos, char* nome){
    char aux[7] = "";
    int i = 0;

    
    sprintf(aux,"%d",pontos);
    
    
    for(i = 1; i < 4;i++){
        aux[i] = nome[i+6];
        }
    
    
        
    
    FILE *fp = fopen ("Placar.txt", "r+");

    
    fseek(fp,0,SEEK_END) ;
    fputs(aux,fp);
    fputs("\n",fp); 
    
    fclose(fp);
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,"SCORE",
								"Você foi colocado no rank de pontuação.",NULL);
}