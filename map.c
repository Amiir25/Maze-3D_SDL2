#include "maze.h"

/* Map dimensions */
int map[MAP_HEIGHT][MAP_WIDTH];

/**
 * loadMap - Reads map from a file and stores it in the map array.
 * @filename: Path to the map file.
 *
 * Return: 1 if successful, 0 if error.
 */

int loadMap(const char *filename)
{
	FILE *file;
	char line[MAP_WIDTH + 2]; /* +2 for newline and null terminator */
	int row = 0, col;

	file = fopen(filename, "r");

	/* Check if the file failed to open */
	if (!file)
	{
		fprintf(stderr, "Error: Could not open map file %s\n", filename);
		return (0);
	}

	/* Read the file line by line */
	while (fgets(line, sizeof(line), file) && row < MAP_HEIGHT)
	{
		/* Process each character in the line */
		for (col = 0; col < MAP_WIDTH && line[col] != '\n' && line[col] != '\0'; col++)
		{
			/* Assign map values based on characters */
			if (line[col] == '1')
				map[row][col] = 1;  /* Wall */
			else if (line[col] == '0')
				map[row][col] = 0;  /* Empty space */
			else
			{
				/* Handle invalid characters */
				fprintf(stderr, "Error: Invalid character '%c' in map file\n", line[col]);
				fclose(file);
				return (0);
			}
		}
		row++;
	}
	fclose(file);

	/* Locate an empty space to set the player's start position */
	for (row = 0; row < MAP_HEIGHT; row++)
	{
		/* Iterate through columns to find an open space */
		for (col = 0; col < MAP_WIDTH; col++)
		{
			/* Check if the current tile is an empty space */
			if (map[row][col] == 0)
			{
				/* Set the player's starting position at the center of the tile */
				playerX = col * TILE_SIZE + TILE_SIZE / 2;
				playerY = row * TILE_SIZE + TILE_SIZE / 2;
				printf("Player starts at: (%.2f, %.2f)\n", playerX, playerY);
				return (1);
			}
		}
	}
	return (1);
}
