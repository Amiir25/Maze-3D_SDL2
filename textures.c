#include "maze.h"

/* Define global textures */
SDL_Texture *ceilingTexture = NULL;
SDL_Texture *floorTexture = NULL;
SDL_Texture *wallTextures[4] = {NULL, NULL, NULL, NULL};

/**
 * loadTexture - Loads a texture from file
 * @renderer: The SDL renderer
 * @filename: Path to the texture file
 *
 * Return: Pointer to the loaded texture, or NULL on failure
 */
SDL_Texture *loadTexture(SDL_Renderer *renderer, const char *filename)
{
    SDL_Surface *surface = IMG_Load(filename);
    if (!surface)
    {
        fprintf(stderr, "Error loading texture %s: %s\n", filename, IMG_GetError());
        return NULL;
    }

    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    if (!texture)
    {
        fprintf(stderr, "Error creating texture from %s: %s\n", filename, SDL_GetError());
    }

    return texture;
}

/**
 * loadTextures - Loads all textures for walls, floor, and ceiling.
 * @renderer: The SDL renderer
 *
 * Return: 1 on success, 0 on failure
 */
int loadTextures(SDL_Renderer *renderer)
{
    ceilingTexture = loadTexture(renderer, "textures/ceiling.png");
    floorTexture = loadTexture(renderer, "textures/floor.png");
    wallTextures[0] = loadTexture(renderer, "textures/wall_north.png");
    wallTextures[1] = loadTexture(renderer, "textures/wall_south.png");
    wallTextures[2] = loadTexture(renderer, "textures/wall_east.png");
    wallTextures[3] = loadTexture(renderer, "textures/wall_west.png");

    if (!ceilingTexture || !floorTexture ||
        !wallTextures[0] || !wallTextures[1] ||
        !wallTextures[2] || !wallTextures[3])
    {
        return 0;
    }
    return 1;
}

/**
 * freeTextures - Frees all loaded textures.
 */
void freeTextures()
{
    if (ceilingTexture) SDL_DestroyTexture(ceilingTexture);
    if (floorTexture) SDL_DestroyTexture(floorTexture);
    for (int i = 0; i < 4; i++)
    {
        if (wallTextures[i]) SDL_DestroyTexture(wallTextures[i]);
    }
}
