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
 * Return: Returns the index of the first match found in the array
 * by the called function
 * or -1 if no matches were found or if the function fails
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (size <= 0 || array == NULL || (*cmp) == NULL)
	{
		return (-1);
	}
	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]) != 0)
		{
			return (i);
		}
	}
	return (-1);
}
