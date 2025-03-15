#ifndef MAZE_H
#define MAZE_H

#include <stdio.h>
#include <SDL2/SDL.h>
#include <math.h>
#include <stdbool.h>


#define TILE_SIZE 64
#define FOV 60
#define NUM_RAYS SCREEN_WIDTH
#define ROTATION_SPEED 5.0

/* Window dimensions */
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

/* Map dimensions */
#define MAP_WIDTH 8
#define MAP_HEIGHT 8

extern float playerX, playerY, playerAngle;
extern int map[MAP_HEIGHT][MAP_WIDTH];

void render(SDL_Renderer *renderer);
void drawWalls(SDL_Renderer *renderer);
void handleInput(SDL_Event event);
void loadMap();

#endif /* MAZE_H */
