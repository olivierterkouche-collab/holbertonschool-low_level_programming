#include "main.h"

/**
 * _strchr - give a pointer set on the
 * first occurence of a given character
 * @s: the string of character we search
 * @c: the character we are scanning for
 *
 * Return: Returns a pointer to the first
 * occurence of the given character
 */
char *_strchr(char *s, char c)
{
	int slen = _strlen(s);
	char **p;
	int i;

	p = &s;
	for (i = 0; i < slen; i++)
	{
		if (s[i] == c)
		{
			return (*p);
		}
	}
	return (0);
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
