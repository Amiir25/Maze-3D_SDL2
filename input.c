#include "maze.h"

float playerX = 100, playerY = 100;
float playerAngle = 0.0;
float moveSpeed = 4.0;  /* Speed of movement */
float rotationSpeed = 5.0;

/**
 * checkCollision - Checks if the player is colliding with a wall.
 * @x: New X position.
 * @y: New Y position.
 *
 * Return: true if there is a collision, false otherwise.
 */

bool checkCollision(float x, float y)
{
	int mapX = (int)(x / TILE_SIZE);
	int mapY = (int)(y / TILE_SIZE);

	if (mapX < 0 || mapX >= MAP_WIDTH || mapY < 0 || mapY >= MAP_HEIGHT)
		return (true);  /* Prevent out-of-bounds movement */
	return (map[mapY][mapX] == 1);
}

/**
 * handleInput - Handles keyboard inputs to control player movement.
 * @event: The SDL_Event structure containing input data.
 */

void handleInput(void)
{
	const Uint8 *keystate = SDL_GetKeyboardState(NULL);
	float newX, newY;

	/* Rotate player */
	if (keystate[SDL_SCANCODE_LEFT])
		playerAngle -= rotationSpeed;
	if (keystate[SDL_SCANCODE_RIGHT])
		playerAngle += rotationSpeed;

	/* Calculate movement */
	if (keystate[SDL_SCANCODE_UP]) /* Move forward */
	{
		newX = playerX + cos(playerAngle * M_PI / 180.0) * moveSpeed;
		newY = playerY + sin(playerAngle * M_PI / 180.0) * moveSpeed;
		if (!checkCollision(newX, newY))
			playerX = newX, playerY = newY;
	}
	if (keystate[SDL_SCANCODE_DOWN]) /* Move backward */
	{
		newX = playerX - cos(playerAngle * M_PI / 180.0) * moveSpeed;
		newY = playerY - sin(playerAngle * M_PI / 180.0) * moveSpeed;
		if (!checkCollision(newX, newY))
			playerX = newX, playerY = newY;
	}
	if (keystate[SDL_SCANCODE_A]) /* Strafe left */
	{
		newX = playerX - sin(playerAngle * M_PI / 180.0) * moveSpeed;
		newY = playerY + cos(playerAngle * M_PI / 180.0) * moveSpeed;
		if (!checkCollision(newX, newY))
			playerX = newX, playerY = newY;
	}
	if (keystate[SDL_SCANCODE_D]) /* Strafe right */
	{
		newX = playerX + sin(playerAngle * M_PI / 180.0) * moveSpeed;
		newY = playerY - cos(playerAngle * M_PI / 180.0) * moveSpeed;
		if (!checkCollision(newX, newY))
			playerX = newX, playerY = newY;
	}
}
