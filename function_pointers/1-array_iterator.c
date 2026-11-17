#include <stdio.h>
#include <stdlib.h>
#include "function_pointers.h"

/**
 * array_iterator - Uses the function pointed by action
 * on all the members of a given array
 * @array: the array we use
 * @size: size of the array
 * @action: pointer to functions we use on the array
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned int i;

	for (i = 0; i < size; i++)
	{
		action(array[i]);
	}
}
