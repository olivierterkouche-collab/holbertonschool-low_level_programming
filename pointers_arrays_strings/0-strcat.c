#include "main.h"

/**
 * _strcat - Apends a string to another
 * @dest: string that get another apended
 * @src: Apended string
 *
 * Return: Returns the string that had
 * another appended to it
 */
char *_strcat(char *dest, char *src)
{
	int srclen = _strlen(src);
	int destlen = _strlen(dest);
	int i;

	for (i = 0; i <= srclen; i++)
	{
		dest[i + (destlen - 1)] = src[i];
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
