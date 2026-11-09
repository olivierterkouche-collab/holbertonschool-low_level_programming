#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * free_grid - frees all the memory alocated to a
 * 2D array
 * @grid: doble pointer containing the adresses of all rows
 * @height: number of rows contained in the 2D array
 */
void free_grid(int **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
	{
		free(grid[i]);
	}
	free(grid);
}
