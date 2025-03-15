#include "maze.h"

void handleInput(SDL_Event event) {
    if (event.type == SDL_KEYDOWN) {
        if (event.key.keysym.sym == SDLK_LEFT) {
            playerAngle -= ROTATION_SPEED;
        } else if (event.key.keysym.sym == SDLK_RIGHT) {
            playerAngle += ROTATION_SPEED;
        }
    }
}
