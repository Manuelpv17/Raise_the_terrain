#include "grid.h"

/**
 * draw - Drawing!
 * @instance: struct with window and renderer
 * @angle: rotation angle
 */
void draw(SDL_Instance instance, int angle)
{
	int x, y, row, column, i;
	double lenght, delta, delta_x, delta_y, rad;
	int terrain[8][8];

	terrain_func(&terrain);

	delta_x = (SCREEN_WIDTH - (SCREEN_MARGIN * 2)) / 14;
	delta_y = (SCREEN_HEIGHT - (SCREEN_MARGIN * 2)) / 14;

	SDL_SetRenderDrawColor(instance.renderer, 0xFF, 0xFF, 0xFF, 0xFF);

	rad = angle * M_PI / 180;

	for (row = 0; row < 8; row++)
		for (i = 7, x = SCREEN_MARGIN + (row * delta_x),
			y = (SCREEN_HEIGHT / 2) + (row * delta_y);
			 i > 0; x += delta_x, y -= delta_y, i--)
			SDL_RenderDrawLine(instance.renderer,
							   (SCREEN_WIDTH / 2) + ((x - (SCREEN_WIDTH / 2)) * cos(rad)),
							   y - terrain[i][row],
							   (SCREEN_WIDTH / 2) +
								   (((x + delta_x) - (SCREEN_WIDTH / 2)) * cos(rad)),
							   y - delta_y - terrain[i - 1][row]);

	for (column = 0; column < 8; column++)
		for (i = 0, x = (SCREEN_WIDTH / 2) - (column * delta_x),
			y = SCREEN_MARGIN + (column * delta_y);
			 i < 7; x += delta_x, y += delta_y, i++)
			SDL_RenderDrawLine(instance.renderer,
							   (SCREEN_WIDTH / 2) + ((x - (SCREEN_WIDTH / 2)) * cos(rad)),
							   y - terrain[column][i],
							   (SCREEN_WIDTH / 2) +
								   (((x + delta_x) - (SCREEN_WIDTH / 2)) * cos(rad)),
							   y + delta_y - terrain[column][i + 1]);
}
