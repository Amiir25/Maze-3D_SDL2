#include "maze.h"

/**
 * drawMinimap - Renders the 2D minimap on the screen.
 * @renderer: The SDL renderer.
 */

void drawMinimap(SDL_Renderer *renderer)
{
	int row, col;
	SDL_Rect tileRect;
	int minimapX, minimapY;

	/* Draw the minimap */
	for (row = 0; row < MAP_HEIGHT; row++)
	{
		for (col = 0; col < MAP_WIDTH; col++)
		{
			minimapX = col * MINIMAP_TILE_SIZE;
			minimapY = row * MINIMAP_TILE_SIZE;

			if (map[row][col] == 1) /* Wall */
				SDL_SetRenderDrawColor(renderer, 80, 80, 80, 255);
			else
				SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255); /* Empty space */

			tileRect.x = minimapX;
			tileRect.y = minimapY;
			tileRect.w = MINIMAP_TILE_SIZE;
			tileRect.h = MINIMAP_TILE_SIZE;

			SDL_RenderFillRect(renderer, &tileRect);
		}
	}

	/* Draw player position */
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_Rect playerRect = {
		(int)(playerX * MINIMAP_SCALE) - 2,
		(int)(playerY * MINIMAP_SCALE) - 2,
		4, 4
	};
	SDL_RenderFillRect(renderer, &playerRect);

	/* Draw player's line of sight */
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	float lineEndX = playerX + cos(playerAngle * M_PI / 180.0) * 20;
	float lineEndY = playerY + sin(playerAngle * M_PI / 180.0) * 20;
	SDL_RenderDrawLine(renderer,
		(int)(playerX * MINIMAP_SCALE), (int)(playerY * MINIMAP_SCALE),
		(int)(lineEndX * MINIMAP_SCALE), (int)(lineEndY * MINIMAP_SCALE));
}
