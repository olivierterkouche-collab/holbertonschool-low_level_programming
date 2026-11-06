#include "main.h"

/**
 * _strpbrk - finds the first occurence
 * of strings in a list in a given string
 * @s: String we opperate on
 * @accept: List of checked characters
 *
 * Return: Returns a pointer to the first
 * match or 0 if no match were found in the
 * string
 */
char *_strpbrk(char *s, char *accept)
{
	char *saveacc = accept;

	while (*s != '\0')
	{
		accept = saveacc;
		while (*accept != '\0')
		{
			if (*s == *accept)
			{
				return (s);
			}
			accept++;
		}
		s++;
	}
	return (0);
}
