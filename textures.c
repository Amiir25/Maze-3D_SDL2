#include "maze.h"

/* SDL Texture pointers */
SDL_Texture *wallTexture = NULL;
SDL_Texture *floorTexture = NULL;
SDL_Texture *ceilingTexture = NULL;

/**
 * loadTextures - Loads textures into memory.
 * @renderer: The SDL renderer.
 *
 * Return: 1 on success, 0 on failure.
 */
int loadTextures(SDL_Renderer *renderer)
{
    SDL_Surface *tempSurface;

    tempSurface = IMG_Load("wall.png");
    if (!tempSurface)
    {
        fprintf(stderr, "Error: Could not load wall texture\n");
        return (0);
    }
    wallTexture = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_FreeSurface(tempSurface);

    tempSurface = IMG_Load("floor.png");
    if (!tempSurface)
    {
        fprintf(stderr, "Error: Could not load floor texture\n");
        return (0);
    }
    floorTexture = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_FreeSurface(tempSurface);

    tempSurface = IMG_Load("ceiling.png");
    if (!tempSurface)
    {
        fprintf(stderr, "Error: Could not load ceiling texture\n");
        return (0);
    }
    ceilingTexture = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_FreeSurface(tempSurface);

    return (1);
}

/**
 * freeTextures - Frees loaded textures.
 */
void freeTextures()
{
    if (wallTexture)
        SDL_DestroyTexture(wallTexture);
    if (floorTexture)
        SDL_DestroyTexture(floorTexture);
    if (ceilingTexture)
        SDL_DestroyTexture(ceilingTexture);
}
