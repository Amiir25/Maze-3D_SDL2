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
        int wallHeight = (int)(SCREEN_HEIGHT / castRay(rayAngle));

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
    if (angle > 45 && angle <= 135)
        return NORTH;
    if (angle > 135 && angle <= 225)
        return WEST;
    if (angle > 225 && angle <= 315)
        return SOUTH;
    return EAST;
}
