#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * alloc_grid - allocates memory and creates a 2D array
 * then initializes it full of 0
 * @width: desired width of our 2D array
 * @height: desired height of our 2D array
 *
 * Return: Returns a pointer to our 2D array
 * or NULL if memory allocation fails
 */
int **alloc_grid(int width, int height)
{
	int **grid;
	int i;
	int j;

	if (width < 1 || height < 1)
	{
		return (NULL);
	}
	grid = malloc(height * sizeof(int *));
	if (grid == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < height; i++)
	{
		grid[i] = malloc(width * sizeof(int));
		if (grid[i] == NULL)
		{
			return (NULL);
		}
	}
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			grid[i][j] = 0;
		}
	}
	return (grid);
}
