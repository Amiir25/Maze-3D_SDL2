#ifndef MAZE_H
#define MAZE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

#define MAP_WIDTH 10
#define MAP_HEIGHT 10

#define PLAYER_SPEED 3.0
#define ROTATION_SPEED 3.0
#define TILE_SIZE 64
/* Directions for wall textures */
#define NORTH 0
#define SOUTH 1
#define EAST  2
#define WEST  3

/* Minimap scaling */
#define MINIMAP_TILE_SIZE 10
#define MINIMAP_SCALE 0.2

#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

/* External variables */
extern float playerX, playerY, playerAngle;
extern int map[MAP_HEIGHT][MAP_WIDTH];
extern bool isShooting;

/* SDL Texture references */
extern SDL_Texture *wallTextures[4];
extern SDL_Texture *floorTexture;
extern SDL_Texture *ceilingTexture;
extern SDL_Texture *weaponTexture;

/* Function prototypes */
int loadTextures(SDL_Renderer *renderer);
void freeTextures(void);

void handleInput(SDL_Event event);
void updatePlayer(void);
void updateMovement(void);  /* FIXED: Added missing function */

void render(SDL_Renderer *renderer);
void drawWalls(SDL_Renderer *renderer);
void drawFloorAndCeiling(SDL_Renderer *renderer);

float castRay(float angle);
int getWallTextureIndex(float angle);

void drawMinimap(SDL_Renderer *renderer);
int loadMap(const char *filename);  /* FIXED: Added missing function */
SDL_Texture *loadTexture(SDL_Renderer *renderer, const char *filePath);

#endif /* MAZE_H */
