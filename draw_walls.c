#include "maze.h"

// Simple map: 1 = Wall, 0 = Empty space
int map[MAP_HEIGHT][MAP_WIDTH] = {
    {1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 1, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1}
};

// Player state
float playerX = 100, playerY = 100;
float playerAngle = 0.0;

void drawWalls(SDL_Renderer *renderer) {
    for (int x = 0; x < NUM_RAYS; x++) {
        float rayAngle = playerAngle - (FOV / 2) + (x * (float)FOV / NUM_RAYS);
        
        float rayX = playerX, rayY = playerY;
        float deltaX = cos(rayAngle * M_PI / 180.0);
        float deltaY = sin(rayAngle * M_PI / 180.0);
        
        // Raycasting algorithm
        while (true) {
            int mapX = (int)(rayX / TILE_SIZE);
            int mapY = (int)(rayY / TILE_SIZE);
            if (mapX < 0 || mapX >= MAP_WIDTH || mapY < 0 || mapY >= MAP_HEIGHT || map[mapY][mapX] == 1) {
                break;
            }
            rayX += deltaX;
            rayY += deltaY;
        }
        
        float dist = sqrt(pow(rayX - playerX, 2) + pow(rayY - playerY, 2));
        int wallHeight = (int)(TILE_SIZE * SCREEN_HEIGHT / dist);
        
        // Set wall color (simple shading based on angle)
        SDL_SetRenderDrawColor(renderer, 200, 0, 0, 255);
        SDL_RenderDrawLine(renderer, x, (SCREEN_HEIGHT / 2) - (wallHeight / 2), x, (SCREEN_HEIGHT / 2) + (wallHeight / 2));
    }
}
