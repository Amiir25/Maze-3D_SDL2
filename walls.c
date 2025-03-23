#include "maze.h"

/**
 * drawWalls - Uses raycasting to draw textured walls.
 * @renderer: The SDL renderer.
 */
void drawWalls(SDL_Renderer *renderer)
{
	int x, mapX, mapY, wallHeight, wallTop, wallBottom;
	float rayAngle, rayAngleRad, rayX, rayY, deltaX, deltaY, dist;
	SDL_Rect srcRect, destRect;

	for (x = 0; x < NUM_RAYS; x++)
	{
		/* Compute the ray angle */
		rayAngle = (playerAngle - (FOV / 2)) + (x * ((float)FOV / NUM_RAYS));
		rayAngleRad = rayAngle * M_PI / 180.0; /* Convert to radians */
		rayX = playerX;
		rayY = playerY;
		deltaX = cos(rayAngleRad);
		deltaY = sin(rayAngleRad);

		/* Perform raycasting */
		while (1)
		{
			mapX = (int)(rayX / TILE_SIZE);
			mapY = (int)(rayY / TILE_SIZE);

			if (mapX < 0 || mapX >= MAP_WIDTH ||
			    mapY < 0 || mapY >= MAP_HEIGHT ||
			    map[mapY][mapX] == 1)
			{
				break;
			}
			rayX += deltaX;
			rayY += deltaY;
		}

		/* Correct fish-eye distortion */
		dist = sqrt(pow(rayX - playerX, 2) + pow(rayY - playerY, 2));
		dist *= cos((rayAngle - playerAngle) * M_PI / 180.0);
		wallHeight = (int)(TILE_SIZE * SCREEN_HEIGHT / (dist + 0.0001));

		/* Compute wall boundaries */
		wallTop = (SCREEN_HEIGHT / 2) - (wallHeight / 2);
		wallBottom = (SCREEN_HEIGHT / 2) + (wallHeight / 2);
		if (wallTop < 0)
			wallTop = 0;
		if (wallBottom > SCREEN_HEIGHT)
			wallBottom = SCREEN_HEIGHT;

		/* Select texture portion */
		srcRect.y = 0;
		srcRect.w = 64; /* Texture width */
		srcRect.h = 64; /* Texture height */
		srcRect.x = (int)(rayX) % 64; /* Sample column from texture */

		/* Destination rectangle */
		destRect.x = x;
		destRect.y = wallTop;
		destRect.w = 1;
		destRect.h = wallBottom - wallTop;

		/* Render wall */
		if (wallTexture)
			SDL_RenderCopy(renderer, wallTexture, &srcRect, &destRect);
		else
		{
			SDL_SetRenderDrawColor(renderer, 80, 80, 80, 255);
			SDL_RenderDrawLine(renderer, x, wallTop, x, wallBottom);
		}
	}
}
