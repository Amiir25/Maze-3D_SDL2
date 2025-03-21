#include "maze.h"

/**
 * main - Entry point
 * @argc: Number of arguments
 * @argv: Argument values
 *
 * Return: Always 0 (Success)
 */

int main(int argc, char *argv[])
{
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Event event;
	bool running;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <map_file>\n", argv[0]);
		return (1);
	}

	if (!loadMap(argv[1]))
		return (1);

	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("Maze Game",
				SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
				SCREEN_WIDTH, SCREEN_HEIGHT,
				SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

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
