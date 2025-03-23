#include "maze.h"

/* Map: 1 = Wall, 0 = Empty space */
int map[MAP_HEIGHT][MAP_WIDTH] = {
	{1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 1, 0, 1, 1, 0, 1},
	{1, 0, 1, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 1, 1, 0, 1},
	{1, 0, 1, 0, 1, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1}
};

/**
 * loadMap - Initializes the game map.
 * This function is currently a placeholder but allows
 * easy modification for future dynamic map loading.
 */
void loadMap(void)
{
	/* In the future, this could load a map from a file */
}
