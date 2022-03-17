#include "maze.h"

/**
 * init_instance - Initializes a new SDL instance.
 * @instance: An instance is mainly characterized by a
 * window and a renderer
 * @flag1: If fullscreen, displays window in fullscreen mode
 *
 * Return: 0 on success, 1 otherwise
 */
int init_instance(SDL_Instance *instance, char *flag1)
{
	/* Initialize SDL */
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		fprintf(stderr, "Unable to initialize SDL: %s\n",
			SDL_GetError());
		return (1);
	}

	/* Create a new Window instance */
	if (strcmp(flag1, "fullscreen") == 0)
	{
		instance->window = SDL_CreateWindow("M A Z E",
						    SDL_WINDOWPOS_CENTERED,
						    SDL_WINDOWPOS_CENTERED, 1260,
						    720, SDL_WINDOW_FULLSCREEN);
	}
	else
	{
		instance->window = SDL_CreateWindow("M A Z E",
						    SDL_WINDOWPOS_CENTERED,
						    SDL_WINDOWPOS_CENTERED, 700,
						    500, 0);
	}
	if (instance->window == NULL)
	{
		fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
		SDL_Quit();
		return (1);
	}

	/* Create a new Window instance */
	instance->renderer = SDL_CreateRenderer(instance->window, -1,
						SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (instance->renderer == NULL)
	{
		SDL_DestroyWindow(instance->window);
		fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
		return (1);
	}
	return (0);
}

/**
 * poll_events - Handles events for the game e.g keypresses
 *
 * Return: An int
 **/
int poll_events(void)
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
			/* if escape is pressed */
			if (key.keysym.scancode == SDL_SCANCODE_ESCAPE)
				return (1);
			break;
		}
	}
	return (0);
}
