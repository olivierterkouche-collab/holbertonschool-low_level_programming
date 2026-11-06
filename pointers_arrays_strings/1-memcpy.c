#include "main.h"

/**
 * _memcpy - Copies n elements of a string
 * to an other
 * @dest: string recieving the modifications
 * @src: string we copy
 * @n: number of characters we copy
 *
 * Return: Returns the edited string
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
