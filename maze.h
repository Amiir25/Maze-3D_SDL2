#ifndef MAZE_H
#define MAZE_H

/*----- Header files ------*/
#include <SDL2/SDL.h>
#include <math.h>
#include <stdio.h>

/*------ Preprocessors ------*/

/* Window diesions */
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

/* Map dimensions */
#define MAP_WIDTH 8
#define MAP_HEIGHT 8

/*------ Functions ------*/
void castRays(SDL_Renderer *);


#endif /* MAZE_H */
