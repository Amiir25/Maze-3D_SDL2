#include "maze.h"

SDL_Texture *wall_north;
SDL_Texture *wall_south;
SDL_Texture *wall_east;
SDL_Texture *wall_west;
SDL_Texture *floor_texture;
SDL_Texture *ceiling_texture;

/**
 * loadTextures - Loads textures for walls, floor, and ceiling.
 * @renderer: The SDL renderer.
 * Return: 1 on success, 0 on failure.
 */
int loadTextures(SDL_Renderer *renderer)
{
    SDL_Surface *surface;

    surface = IMG_Load("textures/wall_north.png");
    if (!surface) { printf("Error loading wall_north.png: %s\n", IMG_GetError()); return 0; }
    wall_north = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("textures/wall_south.png");
    if (!surface) { printf("Error loading wall_south.png: %s\n", IMG_GetError()); return 0; }
    wall_south = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("textures/wall_east.png");
    if (!surface) { printf("Error loading wall_east.png: %s\n", IMG_GetError()); return 0; }
    wall_east = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("textures/wall_west.png");
    if (!surface) { printf("Error loading wall_west.png: %s\n", IMG_GetError()); return 0; }
    wall_west = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("textures/floor.png");
    if (!surface) { printf("Error loading floor.png: %s\n", IMG_GetError()); return 0; }
    floor_texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("textures/ceiling.png");
    if (!surface) { printf("Error loading ceiling.png: %s\n", IMG_GetError()); return 0; }
    ceiling_texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    return (1);
}

/**
 * freeTextures - Frees textures for walls, floor, and ceiling.
 */
void freeTextures()
{
    if (wall_north) SDL_DestroyTexture(wall_north);
    if (wall_south) SDL_DestroyTexture(wall_south);
    if (wall_east) SDL_DestroyTexture(wall_east);
    if (wall_west) SDL_DestroyTexture(wall_west);
    if (floor_texture) SDL_DestroyTexture(floor_texture);
    if (ceiling_texture) SDL_DestroyTexture(ceiling_texture);
}
