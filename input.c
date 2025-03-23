#include "maze.h"

float playerX = 100, playerY = 100;
float playerAngle = 0.0;
float moveSpeed = 5.0;

/**
 * handleInput - Handles keyboard inputs to control player movement and rotation.
 * @event: The SDL_Event structure containing input data.
 */

void handleInput(SDL_Event event)
{
	float newX, newY;
	float radAngle;
	float dx, dy;
	int mapX, mapY;

	if (event.type == SDL_KEYDOWN)
	{
		newX = playerX;
		newY = playerY;
		radAngle = playerAngle * M_PI / 180.0;
		dx = cos(radAngle) * moveSpeed;
		dy = sin(radAngle) * moveSpeed;

		if (event.key.keysym.sym == SDLK_LEFT)
			playerAngle -= ROTATION_SPEED;
		else if (event.key.keysym.sym == SDLK_RIGHT)
			playerAngle += ROTATION_SPEED;
		else if (event.key.keysym.sym == SDLK_UP || event.key.keysym.sym == SDLK_w)
		{
			newX += dx;
			newY += dy;
		}
		else if (event.key.keysym.sym == SDLK_DOWN || event.key.keysym.sym == SDLK_s)
		{
			newX -= dx;
			newY -= dy;
		}
		else if (event.key.keysym.sym == SDLK_a)
		{
			/* Strafe left */
			newX -= dy;
			newY += dx;
		}
		else if (event.key.keysym.sym == SDLK_d)
		{
			/* Strafe right */
			newX += dy;
			newY -= dx;
		}

		/* Prevent walking into walls */
		mapX = (int)(newX / TILE_SIZE);
		mapY = (int)(newY / TILE_SIZE);

		if (mapX >= 0 && mapX < MAP_WIDTH &&
		    mapY >= 0 && mapY < MAP_HEIGHT &&
		    map[mapY][mapX] == 0)
		{
			playerX = newX;
			playerY = newY;
		}
	}
}
