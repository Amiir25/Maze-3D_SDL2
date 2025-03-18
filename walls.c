#include "maze.h"

/**
 * drawWalls - Uses raycasting to draw walls.
 * @renderer: The SDL renderer.
 *
 * This function calculates rays based on the player's position
 * and determines where walls are located in the environment.
 *
 * Return: Nothing
 */

void drawWalls(SDL_Renderer *renderer)
{
	int x;
	float rayAngle, rayX, rayY, deltaX, deltaY, dist;
	int mapX, mapY, wallHeight;
	bool isVerticalWall;

	for (x = 0; x < NUM_RAYS; x++)
	{
		rayAngle = playerAngle - (FOV / 2) + (x * (float)FOV / NUM_RAYS);
		rayX = playerX, rayY = playerY;
		deltaX = cos(rayAngle * M_PI / 180.0);
		deltaY = sin(rayAngle * M_PI / 180.0);
		isVerticalWall = false;

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

		dist = sqrt(pow(rayX - playerX, 2) + pow(rayY - playerY, 2));
		wallHeight = (int)(TILE_SIZE * SCREEN_HEIGHT / dist);

		if (isVerticalWall)
			SDL_SetRenderDrawColor(renderer, 80, 80, 80, 255); /* Dark Gray */
		else
			SDL_SetRenderDrawColor(renderer, 160, 160, 160, 255); /* Light Gray */

		SDL_RenderDrawLine(renderer, x, (SCREEN_HEIGHT / 2) - (wallHeight / 2),
				   x, (SCREEN_HEIGHT / 2) + (wallHeight / 2));
	}
}
