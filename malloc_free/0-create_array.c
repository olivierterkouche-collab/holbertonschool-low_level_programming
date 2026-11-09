#include <stdio.h>
#include "main.h"

/**
 * create_array - create an array and allocates memory for it
 * then initializes it
 * @size: size of the array used to allocate memory
 * @c: char character we use to initialize the array
 *
 * Return: Returns a pointer to the begining of the created array
 */
char *create_array(unsigned int size, char c)
{
	char *ar = &c;

	if (size < 1)
	{
		return (0);
	}
	ar = malloc(size * sizeof(char));
	ar[0] = c;
	return (ar);
}
