#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * _strdup - creates an array and copies a given string into it
 * @str: the original string we copy
 *
 * Return: Returns a pointer to the created array
 * or NULL if malloc failed
 */
char *_strdup(char *str)
{
	unsigned int len = _strlen(str);
	unsigned int i;
	char **ar = &str;

	ar = malloc(len * sizeof(char));
	if (ar == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < len; i++)
	{
		ar[i] = str[i];
	}
	return (ar);
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
