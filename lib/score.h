#ifndef ESCRITA_H_INCLUDED
#define ESCRITA_H_INCLUDED

#include "../lib/desert_falcon.h"
#include "SDL.h"
#include "SDL_ttf.h"
#include <string.h>

    int readPlayerName(int score, SDL_Window* window, SDL_Renderer* renderer);
    void writeScoreboard();

#endif