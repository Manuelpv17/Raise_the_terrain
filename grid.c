#include "grid.h"

/**
 * main - Draw a grid and then raise the terrain
 * Return: 0 for success
 */
int main(void)
{
	SDL_Instance instance;
	int angle = 0;

	if (init_instance(&instance) != 0)
		return (1);

	while (1)
	{
		SDL_SetRenderDrawColor(instance.renderer, 0, 0, 0, 0);
		SDL_RenderClear(instance.renderer);
		if (poll_events(&angle) == 1)
			break;
		draw(instance, angle);
		SDL_RenderPresent(instance.renderer);
	}

	SDL_DestroyRenderer(instance.renderer);
	SDL_DestroyWindow(instance.window);
	SDL_Quit();

	return (0);
}
