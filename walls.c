#include "maze.h"

/**
 * drawWalls - Uses raycasting to draw walls.
 * @renderer: The SDL renderer.
 */

void drawWalls(SDL_Renderer *renderer)
{
	int x, mapX, mapY, wallHeight, wallTop, wallBottom;
	bool isVerticalWall;
	float rayAngle, rayAngleRad, rayX, rayY, deltaX, deltaY, dist;

	for (x = 0; x < NUM_RAYS; x++)
	{
		/* Compute the ray angle */
		rayAngle = (playerAngle - (FOV / 2)) + (x * ((float)FOV / NUM_RAYS));
		rayAngleRad = rayAngle * M_PI / 180.0; /* Convert to radians */
		rayX = playerX;
		rayY = playerY;
		deltaX = cos(rayAngleRad);
		deltaY = sin(rayAngleRad);
		isVerticalWall = false;

		/* Perform raycasting */
		while (1)
		{
			mapX = (int)(rayX / TILE_SIZE);
			mapY = (int)(rayY / TILE_SIZE);

			if (mapX < 0 || mapX >= MAP_WIDTH ||
			    mapY < 0 || mapY >= MAP_HEIGHT ||
			    map[mapY][mapX] == 1)
			{
				isVerticalWall = fabs(deltaX) > fabs(deltaY);
				break;
			}
			rayX += deltaX;
			rayY += deltaY;
		}

		/* Correct fish-eye distortion */
		dist = sqrt(pow(rayX - playerX, 2) + pow(rayY - playerY, 2));
		dist *= cos((rayAngle - playerAngle) * M_PI / 180.0); /* Adjust for fish-eye */
		wallHeight = (int)(TILE_SIZE * SCREEN_HEIGHT / (dist + 0.0001)); /* Avoid div by zero */

		/* Compute wall boundaries */
		wallTop = (SCREEN_HEIGHT / 2) - (wallHeight / 2);
		wallBottom = (SCREEN_HEIGHT / 2) + (wallHeight / 2);
		if (wallTop < 0)
			wallTop = 0;
		if (wallBottom > SCREEN_HEIGHT)
			wallBottom = SCREEN_HEIGHT;

		/* Color walls differently based on orientation */
		if (isVerticalWall)
			SDL_SetRenderDrawColor(renderer, 80, 80, 80, 255); /* Dark Gray */
		else
			SDL_SetRenderDrawColor(renderer, 160, 160, 160, 255); /* Light Gray */

		SDL_RenderDrawLine(renderer, x, wallTop, x, wallBottom);
	}
}
