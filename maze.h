#ifndef MAZE_H
#define MAZE_H

#include <SDL2/SDL.h>
#include <stdbool.h>
#include <math.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

#define MAP_WIDTH 10
#define MAP_HEIGHT 10
#define TILE_SIZE 64

#define MINIMAP_TILE_SIZE 8
#define MINIMAP_SCALE 0.125  /* 1/8 scale for minimap */

#define MOVE_SPEED 5.0
#define ROTATION_SPEED 3.0

/* Global Variables */
extern float playerX, playerY, playerAngle;
extern int map[MAP_HEIGHT][MAP_WIDTH];
extern bool minimapEnabled;

/* Function Declarations */
void handleInput(SDL_Event event);
void updateMovement(void);
void render(SDL_Renderer *renderer);
void drawWalls(SDL_Renderer *renderer);
void drawMinimap(SDL_Renderer *renderer);
bool loadTextures(SDL_Renderer *renderer);
void freeTextures(void);

/* Textures */
extern SDL_Texture *wallTextures[4];
extern SDL_Texture *ceilingTexture;
extern SDL_Texture *floorTexture;

#endif /* MAZE_H */
