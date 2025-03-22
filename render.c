#include "maze.h"

/**
 * render - Renders the game scene.
 * @renderer: The SDL renderer.
 */

void render(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_RenderClear(renderer);

    drawFloorAndCeiling(renderer);
    drawWalls(renderer);
    drawMinimap(renderer);

    /* Shooting animation */
    const char *weaponImg = isShooting ? "textures/weapon_shoot.png" : "textures/weapon.png";
    SDL_Texture *weaponTexture = loadTexture(renderer, weaponImg);

    /* Draw weapon */
    if (weaponTexture)
    {
        SDL_Rect weaponRect = { SCREEN_WIDTH / 2 - 64, SCREEN_HEIGHT - 128, 128, 128 };
        SDL_RenderCopy(renderer, weaponTexture, NULL, &weaponRect);
    }

    SDL_RenderPresent(renderer);
}

/**
 * drawFloorAndCeiling - Renders the floor and ceiling.
 * @renderer: The SDL renderer.
 */

void drawFloorAndCeiling(SDL_Renderer *renderer)
{
    SDL_Rect floorRect = { 0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2 };
    SDL_Rect ceilingRect = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT / 2 };

    SDL_SetRenderDrawColor(renderer, 150, 150, 150, 255); // Gray ceiling
    SDL_RenderFillRect(renderer, &ceilingRect);

    SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255); // Dark floor
    SDL_RenderFillRect(renderer, &floorRect);
}
