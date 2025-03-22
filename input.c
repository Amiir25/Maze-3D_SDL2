#include "maze.h"

bool keys[SDL_NUM_SCANCODES];
bool isShooting = false;

/**
 * handleInput - Handles user input.
 * @event: The SDL event.
 */

void handleInput(SDL_Event event)
{
    if (event.type == SDL_KEYDOWN && event.key.repeat == 0)
    {
        keys[event.key.keysym.scancode] = true;

        if (event.key.keysym.scancode == SDL_SCANCODE_SPACE)
            isShooting = true;
    }
    else if (event.type == SDL_KEYUP)
    {
        keys[event.key.keysym.scancode] = false;

        if (event.key.keysym.scancode == SDL_SCANCODE_SPACE)
            isShooting = false;
    }
}

/**
 * updatePlayer - Moves the player based on input.
 */

void updatePlayer(void)
{
    float moveStep = PLAYER_SPEED;
    float rotationStep = ROTATION_SPEED * (M_PI / 180.0); // Convert to radians

    if (keys[SDL_SCANCODE_W])
    {
        playerX += cos(playerAngle) * moveStep;
        playerY += sin(playerAngle) * moveStep;
    }
    if (keys[SDL_SCANCODE_S])
    {
        playerX -= cos(playerAngle) * moveStep;
        playerY -= sin(playerAngle) * moveStep;
    }
    if (keys[SDL_SCANCODE_A])
    {
        playerX += cos(playerAngle - M_PI_2) * moveStep;
        playerY += sin(playerAngle - M_PI_2) * moveStep;
    }
    if (keys[SDL_SCANCODE_D])
    {
        playerX += cos(playerAngle + M_PI_2) * moveStep;
        playerY += sin(playerAngle + M_PI_2) * moveStep;
    }
    if (keys[SDL_SCANCODE_LEFT])
        playerAngle -= rotationStep;
    if (keys[SDL_SCANCODE_RIGHT])
        playerAngle += rotationStep;
}
