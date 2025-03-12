#include "maze.h"

/* Player properties */
float playerX = 3.5, playerY = 3.5; /* Start in the middle of a cell */
float playerAngle = 0.0; /* Direction the player is facing */

/* Simple 2D grid map (1 = map, 0 = empty space) */
int map [MAP_WIDTH][MAP_HEIGHT] = {
  {1, 1, 1, 1, 1, 1, 1, 1},
  {1, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 1, 0, 1, 1, 0, 1},
  {1, 0, 1, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 1, 1, 0, 1},
  {1, 0, 1, 0, 1, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 1},
  {1, 1, 1, 1, 1, 1, 1, 1},
};


// Raycasting function to render walls
void castRays(SDL_Renderer *renderer) {
    // Draw the sky (top half)
    SDL_SetRenderDrawColor(renderer, 135, 206, 235, 255); // Sky blue
    SDL_Rect sky = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT / 2};
    SDL_RenderFillRect(renderer, &sky);

    // Draw the ground (bottom half)
    SDL_SetRenderDrawColor(renderer, 34, 139, 34, 255); // Ground green
    SDL_Rect ground = {0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2};
    SDL_RenderFillRect(renderer, &ground);

    for (int x = 0; x < SCREEN_WIDTH; x++) {
        float rayAngle = playerAngle + (x - SCREEN_WIDTH / 2) * (M_PI / 180.0) * 60 / SCREEN_WIDTH;
        
        float rayX = playerX;
        float rayY = playerY;
        float rayDirX = cos(rayAngle);
        float rayDirY = sin(rayAngle);

        int mapX, mapY;
        int hit = 0;
        int wallSide = 0; // 0 = North/South, 1 = East/West

        while (!hit) {
            rayX += rayDirX * 0.05;
            rayY += rayDirY * 0.05;

            mapX = (int)rayX;
            mapY = (int)rayY;

            if (mapX < 0 || mapX >= MAP_WIDTH || mapY < 0 || mapY >= MAP_HEIGHT) {
                hit = 1;
            } else if (map[mapX][mapY] == 1) {
                hit = 1;

                // Determine wall orientation
                if (fabs(rayDirX) > fabs(rayDirY)) {
                    wallSide = 1; // East/West wall
                } else {
                    wallSide = 0; // North/South wall
                }
            }
        }

        // Calculate distance to wall
        float distance = sqrt((rayX - playerX) * (rayX - playerX) + (rayY - playerY) * (rayY - playerY));

        // Projected wall height
        int wallHeight = (int)(SCREEN_HEIGHT / distance);

        // Define the rectangle for the wall slice
        SDL_Rect wallSlice;
        wallSlice.x = x; // Column position
        wallSlice.y = (SCREEN_HEIGHT - wallHeight) / 2; // Center vertically
        wallSlice.w = 1; // Column width (we could increase this to smooth the rendering)
        wallSlice.h = wallHeight; // Wall height

        // Set different colors for different wall orientations
        if (wallSide == 0) {
            SDL_SetRenderDrawColor(renderer, 169, 169, 169, 255); // Light gray for North/South
        } else {
            SDL_SetRenderDrawColor(renderer, 105, 105, 105, 255); // Dark gray for East/West
        }

        // Draw the filled wall column
        SDL_RenderFillRect(renderer, &wallSlice);
    }
}
