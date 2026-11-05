#include "main.h"

/**
 * _strncpy - copies set number of elements
 * of a string into an array
 * @dest: Destination array
 * @src: Source string
 * @n: number of elements we want to copy
 *
 * Return: Returns destination pointer
 */
char *_strncpy(char *dest, char *src, int n)
{
	int destlen = _strlen(dest);
	int srclen = _strlen(src);
	int i;

	for (i = 0; i < n; i++)
	{
		if (i == destlen)
		{
			dest[i] = '\0';
			return (dest);
		}
		if (i > srclen)
		{
			dest[i] = '\0';
		}
		else
		{
			dest[i] = src[i];
		}
	}
	return (dest);
}

/**
 * _strlen - counts the elements of a string
 * @s: a string we want to count the elements of
 *
 * Return: Returns strilen the value
 * containing the counted string elements
 */
int _strlen(char *s)
{
	int i;
	int strilen = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		strilen++;
	}
	return (strilen);
}
