#ifndef MAZE_H
#define MAZE_H

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdbool.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
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

#endif /* MAZE_H */
