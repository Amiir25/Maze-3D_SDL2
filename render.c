#include "maze.h"

void render(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
    SDL_RenderClear(renderer);
    
    drawWalls(renderer);
    
    SDL_RenderPresent(renderer);
}
