#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * array_range - creates an array allocates memorry for it
 * and fills it with the values between min and max
 * min and max included
 * @min: the lowest value
 * @max: the highest value
 *
 * Return: Returns a pointer to the created array
 * or NULL if either min is greater than max
 * or if malloc fails
 */
int *array_range(int min, int max)
{
	int *arr;
	int i;
	int j = 0;

	if (min > max)
	{
		return (NULL);
	}
	arr = malloc((max - min + 1) * sizeof(int));
	if (arr == NULL)
	{
		return (NULL);
	}
	for (i = min; i <= max; i++)
	{
		arr[j] = i;
		j++;
	}
	return (arr);
}
