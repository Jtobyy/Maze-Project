#ifndef _MAZE_H_
#define _MAZE_H_

#include <stdio.h>
#include <SDL.h>
#include <string.h>

/**
 * struct SDL_Instance - An instance of SDL characterized by a window and
 * renderer instance
 *
 * @window: An instace of SDL_Window / A variable of type pointer to SDL_Window
 * @renderer: An instace of SDL_Renderer
 **/
typedef struct SDL_Instance
{
	SDL_Window *window;
	SDL_Renderer *renderer;
} SDL_Instance;

int init_instance(SDL_Instance *, char *flag1);
int poll_events(void);
void update(void);
void clean(void);


#endif
