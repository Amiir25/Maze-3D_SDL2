#include "maze.h"

int map[MAP_HEIGHT][MAP_WIDTH];

/**
 * loadMap - Loads the map for the game
 *
 * Return: Nothing
 */

void loadMap(void)
{
	int tempMap[MAP_HEIGHT][MAP_WIDTH] = {
		{1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 1, 0, 1, 1, 0, 1},
		{1, 0, 1, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 1, 1, 0, 1},
		{1, 0, 1, 0, 1, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1}
	};

	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
			map[i][j] = tempMap[i][j];
	}
}
