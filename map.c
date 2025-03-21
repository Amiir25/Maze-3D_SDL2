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
	if (!file)
	{
		fprintf(stderr, "Error: Could not open map file %s\n", filename);
		return (0);
	}

	while (fgets(line, sizeof(line), file) && row < MAP_HEIGHT)
	{
		for (col = 0; col < MAP_WIDTH && line[col] != '\n' && line[col] != '\0'; col++)
		{
			if (line[col] == '1')
				map[row][col] = 1;  /* Wall */
			else if (line[col] == '0')
				map[row][col] = 0;  /* Empty space */
			else
			{
				fprintf(stderr, "Error: Invalid character '%c' in map file\n", line[col]);
				fclose(file);
				return (0);
			}
		}
		row++;
	}

	fclose(file);
	return (1);
}
