#include "main.h"

/**
 * _memset - sets n characters of a string to
 * a constant byte
 * @s: string we opperate on
 * @b: constant byte
 * @n: range of the string we change
 *
 * Return: return edited string
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}
	return (s);
}
