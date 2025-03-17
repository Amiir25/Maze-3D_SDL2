#include "maze.h"

/**
 * main - Entry
 *
 * Return: Always zero (Success)
 */

int main(void)
{
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Event event;
	bool running;

	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("Maze Game",
				SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
				SCREEN_WIDTH, SCREEN_HEIGHT,
				SDL_WINDOW_SHOWN);

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	loadMap();  /* Initialize map */
	running = true;

	while (running)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				running = false;

			handleInput(event);
		}
		render(renderer);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return (0);
}
