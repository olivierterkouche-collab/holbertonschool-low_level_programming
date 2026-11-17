#include <stdio.h>
#include <stdlib.h>
#include "function_pointers.h"

/**
 * int_index - scans an array to find number of occurences
 * of a given parameter using a pointer to different functions
 * @array: the array we scan
 * @size: size of the array
 * @cmp: a pointer to the used function
 *
 * Return: Returns the number of match found in the array
 * by the called function
 * or -1 if no matches were found or if the function fails
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	unsigned int i;
	int result = 0;

	if (size <= 0)
	{
		return (-1);
	}
	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]) != 0)
		{
			result++;
		}
	}
	if (result == 0)
	{
		return (-1);
	}
	else
	{
		return (result);
	}
}
