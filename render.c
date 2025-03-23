#include "maze.h"

/**
 * render - Renders the game scene, including sky, ground, and walls.
 * @renderer: The SDL renderer to use for drawing.
 */

void render(SDL_Renderer *renderer)
{
	SDL_Rect skyRect, groundRect;
	SDL_RenderClear(renderer);

	/* Draw sky (ceiling) */
	if (ceilingTexture)
	{
		SDL_RenderCopy(renderer, ceilingTexture, NULL, NULL);
	}
	else
	{
		skyRect.x = 0;
		skyRect.y = 0;
		skyRect.w = SCREEN_WIDTH;
		skyRect.h = SCREEN_HEIGHT / 2;
		SDL_SetRenderDrawColor(renderer, 135, 206, 235, 255); /* Light blue sky */
		SDL_RenderFillRect(renderer, &skyRect);
	}

	/* Draw ground (floor) */
	if (floorTexture)
	{
		SDL_RenderCopy(renderer, floorTexture, NULL, NULL);
	}
	else
	{
		groundRect.x = 0;
		groundRect.y = SCREEN_HEIGHT / 2;
		groundRect.w = SCREEN_WIDTH;
		groundRect.h = SCREEN_HEIGHT / 2;
		SDL_SetRenderDrawColor(renderer, 34, 139, 34, 255); /* Green ground */
		SDL_RenderFillRect(renderer, &groundRect);
	}

	/* Draw walls */
	drawWalls(renderer);

	/* Present the final rendering */
	SDL_RenderPresent(renderer);
}
