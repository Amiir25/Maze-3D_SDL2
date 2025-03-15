#include "maze.h"

float playerX = 100, playerY = 100;
float playerAngle = 0.0;

void drawWalls(SDL_Renderer *renderer) {
    for (int x = 0; x < NUM_RAYS; x++) {
        float rayAngle = playerAngle - (FOV / 2) + (x * (float)FOV / NUM_RAYS);
        float rayX = playerX, rayY = playerY;
        float deltaX = cos(rayAngle * M_PI / 180.0);
        float deltaY = sin(rayAngle * M_PI / 180.0);
        int mapX, mapY;
        bool isVerticalWall = false;

        while (true) {
            mapX = (int)(rayX / TILE_SIZE);
            mapY = (int)(rayY / TILE_SIZE);
            if (mapX < 0 || mapX >= MAP_WIDTH || mapY < 0 || mapY >= MAP_HEIGHT || map[mapY][mapX] == 1) {
                isVerticalWall = fabs(deltaX) > fabs(deltaY);
                break;
            }
            rayX += deltaX;
            rayY += deltaY;
        }

        float dist = sqrt(pow(rayX - playerX, 2) + pow(rayY - playerY, 2));
        int wallHeight = (int)(TILE_SIZE * SCREEN_HEIGHT / dist);

        if (isVerticalWall) {
            SDL_SetRenderDrawColor(renderer, 80, 80, 80, 255);
        } else {
            SDL_SetRenderDrawColor(renderer, 160, 160, 160, 255);
        }
        SDL_RenderDrawLine(renderer, x, (SCREEN_HEIGHT / 2) - (wallHeight / 2), x, (SCREEN_HEIGHT / 2) + (wallHeight / 2));
    }
}
