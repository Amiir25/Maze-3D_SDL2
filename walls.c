#include "maze.h"

/**
 * drawWalls - Uses raycasting to draw textured walls.
 * @renderer: The SDL renderer.
 */
void drawWalls(SDL_Renderer *renderer)
{
    int x, mapX, mapY, wallHeight, wallTop, wallBottom;
    bool isVerticalWall;
    float rayAngle, rayAngleRad, rayX, rayY, deltaX, deltaY, dist;
    SDL_Rect srcRect, destRect;
    SDL_Texture *selected_texture = NULL;

    for (x = 0; x < NUM_RAYS; x++)
    {
        /* Compute the ray angle */
        rayAngle = (playerAngle - (FOV / 2)) + (x * ((float)FOV / NUM_RAYS));
        rayAngleRad = rayAngle * M_PI / 180.0;
        rayX = playerX;
        rayY = playerY;
        deltaX = cos(rayAngleRad);
        deltaY = sin(rayAngleRad);
        isVerticalWall = false;

        /* Perform raycasting */
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

        /* Select correct wall texture */
        if (isVerticalWall)
        {
            if (deltaX > 0) selected_texture = wall_east;
            else selected_texture = wall_west;
        }
        else
        {
            if (deltaY > 0) selected_texture = wall_south;
            else selected_texture = wall_north;
        }

        /* Select texture portion */
        srcRect.y = 0;
        srcRect.w = 64;
        srcRect.h = 64;
        srcRect.x = (int)(rayX) % 64;

        /* Destination rectangle */
        destRect.x = x;
        destRect.y = wallTop;
        destRect.w = 1;
        destRect.h = wallBottom - wallTop;

        /* Render wall */
        if (selected_texture)
            SDL_RenderCopy(renderer, selected_texture, &srcRect, &destRect);
        else
        {
            SDL_SetRenderDrawColor(renderer, 80, 80, 80, 255);
            SDL_RenderDrawLine(renderer, x, wallTop, x, wallBottom);
        }
    }
}
