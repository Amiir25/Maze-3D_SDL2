#ifndef MAZE_H
#define MAZE_H

#include <stdio.h>
#include <SDL2/SDL.h>
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
extern int map[MAP_HEIGHT][MAP_WIDTH];

/* Function prototypes */
void loadMap(void);
void handleInput(void);
void render(SDL_Renderer *renderer);
void drawWalls(SDL_Renderer *renderer);
bool checkCollision(float x, float y);

#endif /* MAZE_H */
