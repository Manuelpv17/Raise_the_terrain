#ifndef GRID_H
#define GRID_H

#include <SDL2/SDL.h>
#include <stdio.h>
#include <math.h>

//Screen dimension constants
const int SCREEN_WIDTH = 1100;
const int SCREEN_HEIGHT = 600;
const int SCREEN_MARGIN = 130;

typedef struct SDL_Instance
{
    SDL_Window *window;
    SDL_Renderer *renderer;
} SDL_Instance;

int init_instance(SDL_Instance *);
int poll_events();

#endif