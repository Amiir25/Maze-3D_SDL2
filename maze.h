#ifndef MAZE_H
#define MAZE_H

/* Header files */
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdbool.h>
#include <math.h>

/* Value of PI */
#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

/* Preprocessor directives */
#define SCREEN_WIDTH 1400
#define SCREEN_HEIGHT 700
#define MAP_WIDTH 8
#define MAP_HEIGHT 8
#define TILE_SIZE 64
#define FOV 60
#define NUM_RAYS SCREEN_WIDTH
#define ROTATION_SPEED 5.0

/* Global variables */
extern float playerX, playerY, playerAngle;
extern float moveSpeed;
extern int map[MAP_HEIGHT][MAP_WIDTH];

/* SDL Texture variables */
extern SDL_Texture *wall_north;
extern SDL_Texture *wall_south;
extern SDL_Texture *wall_east;
extern SDL_Texture *wall_west;
extern SDL_Texture *floor_texture;
extern SDL_Texture *ceiling_texture;

extern SDL_Texture *wallTexture;
extern SDL_Texture *floorTexture;
extern SDL_Texture *ceilingTexture;

/* Function prototypes */
int loadMap(const char *filename);
int loadTextures(SDL_Renderer *renderer);
void freeTextures();
void handleInput(SDL_Event event);
void render(SDL_Renderer *renderer);
void drawWalls(SDL_Renderer *renderer);
void drawFloorAndCeiling(SDL_Renderer *renderer);

#endif /* MAZE_H */
