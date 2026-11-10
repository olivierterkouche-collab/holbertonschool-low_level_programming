#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * malloc_checked - allocates memory for a variable exits if allocation fails
 * with code 98 else initilises it with our parameter
 * @b: value we allocate memory for
 *
 * Return: Returns a pointer to allocated and initialized memory
 */
void *malloc_checked(unsigned int b)
{
	unsigned int *ptr;

	ptr = malloc(sizeof(unsigned int));
	if (ptr == NULL)
	{
		exit(98);
	}
	*ptr = b;
	return (ptr);
}
