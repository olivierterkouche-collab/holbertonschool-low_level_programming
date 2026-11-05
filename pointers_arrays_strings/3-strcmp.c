#include "main.h"

/**
 * _strcmp - compares two strings
 * @s1: string 1
 * @s2: string 2
 *
 * Return: Returns the difference between
 * the elements of string 1 and 2 on
 * the first time they differ
 * if they do not differ at all
 * Returns 0
 */
int _strcmp(char *s1, char *s2)
{
	int i;
	int range;
	int s1len = _strlen(s1);
	int s2len = _strlen(s2);

	if (s1len >= s2len)
	{
		range = s1len - 1;
	}
	else
	{
		range = s2len - 1;
	}

	for (i = 0; i < range; i++)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
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
