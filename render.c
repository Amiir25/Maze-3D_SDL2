#include "maze.h"

/**
 * render - Renders the game scene.
 * @renderer: The SDL renderer.
 */
void render(SDL_Renderer *renderer)
{
    drawWalls(renderer);
    drawFloorAndCeiling(renderer);

    /* Shooting animation */
    const char *weaponImg = isShooting ? "textures/weapon_shoot.png" : "textures/weapon.png";
    weaponTexture = loadTexture(renderer, weaponImg);

    /* Draw weapon */
    if (weaponTexture)
    {
        SDL_Rect weaponRect = { SCREEN_WIDTH / 2 - 64, SCREEN_HEIGHT - 128, 128, 128 };
        SDL_RenderCopy(renderer, weaponTexture, NULL, &weaponRect);
    }

    SDL_RenderPresent(renderer);
}

/**
 * drawFloorAndCeiling - Renders the floor and ceiling textures.
 * @renderer: The SDL renderer.
 */
void drawFloorAndCeiling(SDL_Renderer *renderer)
{
    SDL_Rect floorRect = { 0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2 };
    SDL_Rect ceilingRect = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT / 2 };

    if (floorTexture)
        SDL_RenderCopy(renderer, floorTexture, NULL, &floorRect);

    if (ceilingTexture)
        SDL_RenderCopy(renderer, ceilingTexture, NULL, &ceilingRect);
}
