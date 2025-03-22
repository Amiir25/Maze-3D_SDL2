#include "maze.h"

/**
 * render - Renders the game scene, including textured sky, ground, and walls.
 * @renderer: The SDL renderer to use for drawing.
 */
void render(SDL_Renderer *renderer)
{
    SDL_Rect destRect;

    /* Draw ceiling */
    destRect.x = 0;
    destRect.y = 0;
    destRect.w = SCREEN_WIDTH;
    destRect.h = SCREEN_HEIGHT / 2;
    SDL_RenderCopy(renderer, ceilingTexture, NULL, &destRect);

    /* Draw floor */
    destRect.y = SCREEN_HEIGHT / 2;
    SDL_RenderCopy(renderer, floorTexture, NULL, &destRect);

    /* Draw walls */
    drawWalls(renderer);

    /* Present the final rendering */
    SDL_RenderPresent(renderer);
}
