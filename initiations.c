#include "grid.h"

/**
 * init_instance - SDL initializations
 * @instance: struct with window and renderer
 * Return: 0 at success
 */
int init_instance(SDL_Instance *instance)
{
	/* Initialie SDL */
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
		return (1);
	}
	/* Create a new Window instance */
	instance->window = SDL_CreateWindow("3D Grid", SDL_WINDOWPOS_CENTERED,
										SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
	if (instance->window == NULL)
	{
		fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
		SDL_Quit;
		return (1);
	}
	/* Create a new Renderer instance linked to theWindow */
	instance->renderer = SDL_CreateRenderer(instance->window, -1,
											SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (instance->renderer == NULL)
	{
		SDL_DestroyWindow(instance->window);
		fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
		SDL_Quit();
		return (1);
	}
	return (0);
}
