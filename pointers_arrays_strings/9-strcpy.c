#include "main.h"

/**
 * _strcpy - copies a string to the buffer
 * @dest: pointer to the buffer
 * @src: pointer to the copied string
 *
 * Return: Returns the string copied in buffer
 */
char *_strcpy(char *dest, char *src)
{
	int len = _strlen(src);
	char dest[len];

	for (i = 0; i <= len; i++)
	{
		dest[i] = src[i];
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
