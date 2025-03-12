#include "maze.h"

int main(int argc, char *argv[])
{
	/* Initialize SDL with video subsystem (for creating windows and rendering) */
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL couldn't initialize! SDL_Error: %s\n", SDL_GetError());
		return (1);
	}

	/* Create an SDL window */
	SDL_Window *window = SDL_CreateWindow("Maze-3D_SDL2", /* Window title */
					      SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, /* Position (centered on the screen) */
					      SCREEN_WIDTH, SCREEN_HEIGHT, /* Window size */
					      SDL_WINDOW_SHOWN); /* Show the window when created */

	/* Check if the window was successfully created */
	if (!window)
	{
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		SDL_Quit(); /* Quits SDL if window creation failed */
		return (1);
	}

	/* Create an SDL renderer */
	SDL_Renderer *renderer = SDL_CreateRenderer(window, /* window */
						    -1, /* Best rendering driver available */
						    SDL_RENDERER_ACCELERATED); /* Hardware acceleration*/

	/* Check if the renderer was successfully created */
	if (!renderer)
	{
		printf("Rebderer could not be created! SDL_Error: %s\n", SDL_GetError());
		SDL_DestroyWindow(window); /* Destroy the window before quitting */
		SDL_Quit();
		return (1);
	}

	/* Main loop flag */
	int running = 1;

	/* Event Structure to store events like (keypress and window actions) */
	SDL_Event event;


	/* Main loop */
	while (running)
	{
		/* Process events */
		while (SDL_PollEvent(&event)) /* Check for any pending events */
		{
			if (event.type == SDL_QUIT) /* If the user clicks the close button */
				running = 0;
		}

		/* Set the drawing color for the renderer */
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

		/* Clear the screen with the set color */
		SDL_RenderClear(renderer);

		/* Call the castRays function */
		castRays(renderer);

		/* Present the updated frame (swap buffers) */
		SDL_RenderPresent(renderer);
	}

	/* Cleanup resources before exiting */
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return (0);
}
