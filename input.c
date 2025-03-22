#include "maze.h"

float playerX = 100, playerY = 100;
float playerAngle = 0.0;
float moveSpeed = 5.0;
bool keys[SDL_NUM_SCANCODES] = {false}; /* Array to track key states */

/**
 * handleInput - Updates key state based on events.
 * @event: The SDL_Event structure containing input data.
 */
void handleInput(SDL_Event event)
{
    if (event.type == SDL_KEYDOWN && event.key.repeat == 0)
        keys[event.key.keysym.scancode] = true;
    else if (event.type == SDL_KEYUP)
        keys[event.key.keysym.scancode] = false;
}

/**
 * updateMovement - Processes movement based on pressed keys.
 */
void updateMovement(void)
{
    float newX = playerX, newY = playerY;
    float radAngle = playerAngle * M_PI / 180.0;
    float dx = cos(radAngle) * moveSpeed;
    float dy = sin(radAngle) * moveSpeed;

    /* Rotation */
    if (keys[SDL_SCANCODE_LEFT])
        playerAngle -= ROTATION_SPEED;
    if (keys[SDL_SCANCODE_RIGHT])
        playerAngle += ROTATION_SPEED;

    /* Movement */
    if (keys[SDL_SCANCODE_W] || keys[SDL_SCANCODE_UP])
    {
        newX += dx;
        newY += dy;
    }
    if (keys[SDL_SCANCODE_S] || keys[SDL_SCANCODE_DOWN])
    {
        newX -= dx;
        newY -= dy;
    }
    if (keys[SDL_SCANCODE_A])
    {
        newX -= dy; /* Strafe left */
        newY += dx;
    }
    if (keys[SDL_SCANCODE_D])
    {
        newX += dy; /* Strafe right */
        newY -= dx;
    }

    /* Collision check */
    int mapX = (int)(newX / TILE_SIZE);
    int mapY = (int)(newY / TILE_SIZE);
    if (mapX >= 0 && mapX < MAP_WIDTH && mapY >= 0 && mapY < MAP_HEIGHT && map[mapY][mapX] == 0)
    {
        playerX = newX;
        playerY = newY;
    }
}
