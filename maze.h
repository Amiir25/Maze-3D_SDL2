#ifndef MAZE_H
#define MAZE_H

/*----- Header files ------*/
#include <stdio.h>
#include <SDL2/SDL.h>
#include <math.h>
#include <stdbool.h>

/*------ Preprocessors ------*/
#define TILE_SIZE 64
#define FOV 60
#define NUM_RAYS SCREEN_WIDTH

/* Window dimensions */
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

/* Map dimensions */
#define MAP_WIDTH 8
#define MAP_HEIGHT 8

/*------ Functions ------*/
void drawWalls(SDL_Renderer *);
void render(SDL_Renderer *);


#endif /* MAZE_H */
