#ifndef GRID_H
#define GRID_H

#include <SDL2/SDL.h>
#include <stdio.h>
#include <math.h>

/* Screen dimension  */
#define SCREEN_WIDTH 1100
#define SCREEN_HEIGHT 600
#define SCREEN_MARGIN 130

/**
 * struct SDL_Instance - SDL initializations
 * @window: SDL window
 * @renderer: SDL renderer
 */
typedef struct SDL_Instance
{
	SDL_Window *window;
	SDL_Renderer *renderer;
} SDL_Instance;

int init_instance(SDL_Instance *);
int poll_events(int *angle);
void draw(SDL_Instance instance, int angle);

#endif
