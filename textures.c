#include "maze.h"

SDL_Texture *wallTextures[4];
SDL_Texture *floorTexture = NULL;
SDL_Texture *ceilingTexture = NULL;
SDL_Texture *weaponTexture = NULL;

/**
 * loadTexture - Loads an image as an SDL texture.
 * @renderer: The SDL renderer.
 * @file: Path to the image file.
 * Return: The SDL_Texture or NULL on failure.
 */
SDL_Texture *loadTexture(SDL_Renderer *renderer, const char *file)
{
    SDL_Texture *texture = NULL;
    SDL_Surface *surface = IMG_Load(file);

    if (!surface)
    {
        printf("Error loading texture %s: %s\n", file, IMG_GetError());
        return NULL;
    }
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    return texture;
}

/**
 * loadTextures - Loads textures for walls, floor, ceiling, and weapons.
 * @renderer: The SDL renderer.
 * Return: 1 if successful, 0 on failure.
 */
int loadTextures(SDL_Renderer *renderer)
{
    wallTextures[NORTH] = loadTexture(renderer, "textures/wall_north.png");
    wallTextures[SOUTH] = loadTexture(renderer, "textures/wall_south.png");
    wallTextures[EAST]  = loadTexture(renderer, "textures/wall_east.png");
    wallTextures[WEST]  = loadTexture(renderer, "textures/wall_west.png");
    floorTexture = loadTexture(renderer, "textures/floor.png");
    ceilingTexture = loadTexture(renderer, "textures/ceiling.png");
    weaponTexture = loadTexture(renderer, "textures/weapon.png");

    if (!wallTextures[NORTH] || !wallTextures[SOUTH] || !wallTextures[EAST] ||
        !wallTextures[WEST] || !floorTexture || !ceilingTexture || !weaponTexture)
    {
        printf("Failed to load textures!\n");
        return 0;
    }
    return 1;
}

/**
 * freeTextures - Frees all loaded textures.
 */
void freeTextures(void)
{
    SDL_DestroyTexture(floorTexture);
    SDL_DestroyTexture(ceilingTexture);
    SDL_DestroyTexture(weaponTexture);

    for (int i = 0; i < 4; i++)
        SDL_DestroyTexture(wallTextures[i]);
}
