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
    float moveStep = 3.0;
    float rotationStep = 3.0;

    if (keys[SDL_SCANCODE_W])
    {
        playerX += cos(playerAngle * M_PI / 180.0) * moveStep;
        playerY += sin(playerAngle * M_PI / 180.0) * moveStep;
    }
    if (keys[SDL_SCANCODE_S])
    {
        playerX -= cos(playerAngle * M_PI / 180.0) * moveStep;
        playerY -= sin(playerAngle * M_PI / 180.0) * moveStep;
    }
    if (keys[SDL_SCANCODE_A])
    {
        playerX += cos((playerAngle - 90) * M_PI / 180.0) * moveStep;
        playerY += sin((playerAngle - 90) * M_PI / 180.0) * moveStep;
    }
    if (keys[SDL_SCANCODE_D])
    {
        playerX += cos((playerAngle + 90) * M_PI / 180.0) * moveStep;
        playerY += sin((playerAngle + 90) * M_PI / 180.0) * moveStep;
    }
    if (keys[SDL_SCANCODE_LEFT])
        playerAngle -= rotationStep;
    if (keys[SDL_SCANCODE_RIGHT])
        playerAngle += rotationStep;
}

/**
 * Placeholder: Implement movement logic here
 */

void updateMovement(void) {
    // Placeholder: Implement movement logic here
}
