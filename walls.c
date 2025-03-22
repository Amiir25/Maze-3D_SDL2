#include "maze.h"

/**
 * drawWalls - Uses raycasting to draw textured walls.
 * @renderer: The SDL renderer.
 */
void drawWalls(SDL_Renderer *renderer)
{
    int x;
    float rayAngle, rayX, rayY, deltaX, deltaY, dist;
    int mapX, mapY, wallHeight, textureOffsetX;
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

        /* Determine wall orientation */
        int wallSide = isVerticalWall ? (deltaX > 0 ? 2 : 3) : (deltaY > 0 ? 1 : 0);

        /* Texture offset */
        textureOffsetX = (isVerticalWall ? (int)rayY % TILE_SIZE : (int)rayX % TILE_SIZE);

        /* Wall slice rectangle */
        SDL_Rect wallSlice = {x, (SCREEN_HEIGHT - wallHeight) / 2, 1, wallHeight};
        SDL_Rect textureRect = {textureOffsetX, 0, 1, TEXTURE_HEIGHT};

        /* Render the texture slice */
        SDL_RenderCopy(renderer, wallTextures[wallSide], &textureRect, &wallSlice);
    }
}
