#include "maze.h"

extern SDL_Texture *wallTextures[4];

/**
 * drawWalls - Renders the walls with textures.
 * @renderer: The SDL renderer.
 */
void drawWalls(SDL_Renderer *renderer)
{
    for (int x = 0; x < SCREEN_WIDTH; x++)
    {
        float rayAngle = playerAngle + atan((x - SCREEN_WIDTH / 2) / 600.0);
        float distance = castRay(rayAngle);
        int wallHeight = (int)(SCREEN_HEIGHT / (distance + 0.001)); // Avoid division by zero

        int wallTop = (SCREEN_HEIGHT / 2) - (wallHeight / 2);
        int textureIndex = getWallTextureIndex(rayAngle);
        SDL_Texture *wallTexture = wallTextures[textureIndex];

        SDL_Rect destRect = { x, wallTop, 1, wallHeight };
        SDL_RenderCopy(renderer, wallTexture, NULL, &destRect);
    }
}

/**
 * getWallTextureIndex - Determines which wall texture to use.
 * @angle: The ray angle.
 * Return: The texture index.
 */
int getWallTextureIndex(float angle)
{
    angle = fmod(angle, 360);
    if (angle < 0) angle += 360;

    if (angle > 45 && angle <= 135)
        return NORTH;
    if (angle > 135 && angle <= 225)
        return WEST;
    if (angle > 225 && angle <= 315)
        return SOUTH;
    return EAST;
}

/**
 * castRay - Casts a ray to determine wall distance.
 * @angle: The ray angle.
 * Return: Distance to the nearest wall.
 */
float castRay(float angle)
{
    // Temporary usage to avoid compiler warning
    (void)angle;

    // Placeholder raycasting logic
    return 1.0;
}
