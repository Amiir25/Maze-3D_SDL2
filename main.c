#include "maze.h"

/**
 * main - Entry point of the program
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

	/* Load the map */
	if (!loadMap(argv[1]))
		return (1);

	/* Initialize SDL */
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		fprintf(stderr, "Error: SDL could not initialize. %s\n", SDL_GetError());
		return (1);
	}

	/* Create window */
	window = SDL_CreateWindow("Maze Game",
				SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
				SCREEN_WIDTH, SCREEN_HEIGHT,
				SDL_WINDOW_SHOWN);
	if (!window)
	{
		fprintf(stderr, "Error: Could not create window. %s\n", SDL_GetError());
		SDL_Quit();
		return (1);
	}

	/* Create renderer */
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (!renderer)
	{
		fprintf(stderr, "Error: Could not create renderer. %s\n", SDL_GetError());
		SDL_DestroyWindow(window);
		SDL_Quit();
		return (1);
	}

	/* Load textures */
	if (!loadTextures(renderer))
	{
		fprintf(stderr, "Error: Failed to load textures\n");
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
		return (1);
	}

	/* Game loop */
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

	/* Cleanup */
	freeTextures();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return (0);
}
