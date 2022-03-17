#include "maze.h"

/**
 * main - Game execution function
 *
 * @argc: number of command line arguments
 * @argv: array of command line arguments
 *
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	SDL_Instance instance;
	char *screen;

	if (argc >= 2)
		screen = argv[1];
	else
		screen = "default";

	if (init_instance(&instance, screen) != 0)
	{
		fprintf(stderr, "could not initialize SDL");
		return (1);
	}
	while ("C is fun")
	{
		/* Select the color for drawing. It is set to black here. */
		SDL_SetRenderDrawColor(instance.renderer, 0xff, 0xff, 0xff, 0xff);
		/* Clear the entire screen to our selected color. */
		SDL_RenderClear(instance.renderer);
		if (poll_events() == 1)
			break;
		/**
		 * Up until now everything was drawn behind the scenes.
		 * This will show the new, black contents of the window.
		 **/
		SDL_RenderPresent(instance.renderer);
	}
	SDL_DestroyRenderer(instance.renderer);
	SDL_DestroyWindow(instance.window);
	SDL_Quit();
	return (0);
}
