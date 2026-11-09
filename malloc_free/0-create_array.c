#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * create_array - create an array and allocates memory for it
 * then initializes it
 * @size: size of the array used to allocate memory
 * @c: char character we use to initialize the array
 *
 * Return: Returns a pointer to the begining of the created array
 * Returns 0 if size is 0 or negative
 * Returns NULL if malloc fails
 */
char *create_array(unsigned int size, char c)
{
	char *ar;
	unsigned int i;

	if (size < 1)
	{
		return (0);
	}
	ar = malloc(size * sizeof(char));
	if (ar == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < size; i++)
	{
		ar[i] = c;
	}
	return (ar);
}
