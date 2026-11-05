#include "main.h"

/**
 * _strncat - Appends n characters of a string
 * to another
 * @dest: String receving the apended string
 * @src: String apended
 * @n: number of appended bytes
 *
 * Return: Returns a pointer to dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int destlen = _strlen(dest);
	int i;

	for (i = 0; i < n || src[i] != '\0'; i++)
	{
		dest[i + destlen] = src[i];
		if (src[i] == '\0')
		{
			return (dest);
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
