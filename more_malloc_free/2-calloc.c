#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * _calloc - allocates memory for an array and initializes it to 0
 * @nmemb: number of arguments in the array
 * @size: byte size of an argument of the array
 *
 * Return: Returns a pointer to the created array
 * or NULL if either of the parametes are equal to 0
 * or if malloc fails
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	int *ptr;
	unsigned int i;

	if (nmemb <= 0 || size <= 0)
	{
		return (NULL);
	}
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < (nmemb * size); i++)
	{
		ptr[i] = 0;
	}
	return (ptr);
}
