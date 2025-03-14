#include "maze.h"

void render(SDL_Renderer *renderer) {
    // Draw sky (blue)
    SDL_SetRenderDrawColor(renderer, 135, 206, 235, 255);
    SDL_Rect sky = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT / 2};
    SDL_RenderFillRect(renderer, &sky);
    
    // Draw ground (green)
    SDL_SetRenderDrawColor(renderer, 34, 139, 34, 255);
    SDL_Rect ground = {0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2};
    SDL_RenderFillRect(renderer, &ground);
    
    drawWalls(renderer);
    
    SDL_RenderPresent(renderer);
}
