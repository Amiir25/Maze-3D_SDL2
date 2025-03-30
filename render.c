#include "maze.h"

/**
 * drawFloorAndCeiling - Draws the textured floor and ceiling.
 * @renderer: The SDL renderer.
 */

void drawFloorAndCeiling(SDL_Renderer *renderer)
{
    SDL_Rect floorRect = { 0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2 };
    SDL_Rect ceilingRect = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT / 2 };

    /* Check if a floor texture is available */
    if (floor_texture)
        SDL_RenderCopy(renderer, floor_texture, NULL, &floorRect);
    else
    {
        /* Draw a solid color floor if no texture is available */
        SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
        SDL_RenderFillRect(renderer, &floorRect);
    }

    /* Check if a ceiling texture is available */
    if (ceiling_texture)
        SDL_RenderCopy(renderer, ceiling_texture, NULL, &ceilingRect);
    else
    {
        /* Draw a solid color ceiling if no texture is available */
        SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
        SDL_RenderFillRect(renderer, &ceilingRect);
    }
}

/**
 * render - Renders the game frame.
 * @renderer: The SDL renderer.
 */
void render(SDL_Renderer *renderer)
{
    /* Clear screen */
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    /* Draw scene */
    drawFloorAndCeiling(renderer);
    drawWalls(renderer);

    /* Present frame */
    SDL_RenderPresent(renderer);
}
