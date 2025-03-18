#include "maze.h"

float playerX = 100, playerY = 100;
float playerAngle = 0.0;

/**
 * handleInput - Handles keyboard inputs to control player movement.
 *
 * @event: The SDL_Event structure containing input data.
 */

void handleInput(SDL_Event event)
{
	if (event.type == SDL_KEYDOWN)
	{
		if (event.key.keysym.sym == SDLK_LEFT)
			playerAngle -= ROTATION_SPEED;
		else if (event.key.keysym.sym == SDLK_RIGHT)
			playerAngle += ROTATION_SPEED;
	}
}
