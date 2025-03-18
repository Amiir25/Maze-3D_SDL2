#include "maze.h"

/**
 * render - Renders the game frame.
 * @renderer: The SDL renderer.
 *
 * Draws the sky, ground, and walls to the screen.
 *
 * Return: Nothing
 */

void render(SDL_Renderer *renderer)
{
	SDL_Rect sky, ground;

	/* Draw sky (blue) */
	SDL_SetRenderDrawColor(renderer, 135, 206, 235, 255);
	sky.x = 0, sky.y = 0;
	sky.w = SCREEN_WIDTH, sky.h = SCREEN_HEIGHT / 2;
	SDL_RenderFillRect(renderer, &sky);

	/* Draw ground (green) */
	SDL_SetRenderDrawColor(renderer, 34, 139, 34, 255);
	ground.x = 0, ground.y = SCREEN_HEIGHT / 2;
	ground.w = SCREEN_WIDTH, ground.h = SCREEN_HEIGHT / 2;
	SDL_RenderFillRect(renderer, &ground);

	drawWalls(renderer);
	SDL_RenderPresent(renderer);
}
