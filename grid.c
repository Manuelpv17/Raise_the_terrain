#include "grid.h"

void draw(SDL_Instance instance)
{
    int x, y, row, column;
    double lenght, delta, delta_x, delta_y;
    int matrix[8][8] = {
        120,
        60,
        40,
        60,
        20,
        -20,
        -80,
        -120,
        40,
        20,
        30,
        30,
        -10,
        -40,
        -90,
        -110,
        20,
        30,
        10,
        06,
        -6,
        -20,
        -26,
        -90,
        00,
        -6,
        10,
        10,
        -6,
        -20,
        -20,
        -40,
        -20,
        -20,
        -18,
        -14,
        -40,
        -20,
        -20,
        -30,
        -10,
        -10,
        -10,
        -10,
        -8,
        -20,
        -20,
        -30,
        20,
        10,
        10,
        10,
        10,
        04,
        10,
        -10,
        30,
        24,
        24,
        22,
        20,
        18,
        14,
        16,
    };

    SDL_SetRenderDrawColor(instance.renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    /*
    lenght = sqrt(pow(SCREEN_WIDTH - 10, 2) + pow(SCREEN_HEIGHT - 10, 2));
    delta = lenght / 7;
    */
    delta_x = (SCREEN_WIDTH - (SCREEN_MARGIN * 2)) / 14;
    delta_y = (SCREEN_HEIGHT - (SCREEN_MARGIN * 2)) / 14;

    for (row = 0; row < 8; row++)
    {
        for (x = SCREEN_MARGIN + (row * delta_x), y = (SCREEN_HEIGHT / 2) + (row * delta_y); x < (SCREEN_WIDTH / 2) + (row * delta_x) - 1; x += delta_x, y -= delta_y)
        {
            SDL_RenderDrawLine(instance.renderer, x, y, x + delta_x, y - delta_y);
        }
    }

    for (column = 0; column < 8; column++)
    {
        for (x = (SCREEN_WIDTH / 2) - (column * delta_x), y = SCREEN_MARGIN + (column * delta_y); x < (SCREEN_WIDTH - SCREEN_MARGIN) - (column * delta_x) - 1; x += delta_x, y += delta_y)
        {
            SDL_RenderDrawLine(instance.renderer, x, y, x + delta_x, y + delta_y);
        }
    }
}

int main(int argc, char **argv)
{
    SDL_Instance instance;

    if (init_instance(&instance) != 0)
        return (1);

    while (1)
    {
        SDL_SetRenderDrawColor(instance.renderer, 0, 0, 0, 0);
        SDL_RenderClear(instance.renderer);
        if (poll_events() == 1)
            break;
        draw(instance);
        SDL_RenderPresent(instance.renderer);
    }
    SDL_DestroyRenderer(instance.renderer);
    SDL_DestroyWindow(instance.window);
    SDL_Quit();

    return (0);
}

int poll_events()
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
            break;
        }
    }
    return (0);
}

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
