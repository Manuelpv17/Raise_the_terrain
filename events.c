#include "grid.h"

/**
 * poll_events - Key board events and exit
 * @angle: angle of rotation
 * Return: 0 on success, 1 for exit
 */
int poll_events(int *angle)
{
	SDL_Event event;
	SDL_KeyboardEvent key;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			return (1);
		case SDL_KEYDOWN:
			key = event.key;
			/* if 'ESCAPE' is pressed */
			if (key.keysym.scancode == 0x29)
				return (1);
			/* if 'LEFT' is pressed */
			if (key.keysym.scancode == 80)
				*angle = *angle - 1;
			/* if 'RIGHT' is pressed */
			if (key.keysym.scancode == 79)
				*angle = *angle + 1;
			break;
		}
	}
	return (0);
}
