#include "main.h"

/**
 * _strspn - Search for the number of
 * bytes in the initial segment of a
 * string that consist only of characters
 * contained in a given list
 * @s: The string we opperate on
 * @accept: the list of characters we look
 * for
 *
 * Return: Returns the number of bytes
 * corresponding to our parameters
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int sum = 0;

	while (*s != '\0')
	{
		accept = 0;
		while (*accept != '\0')
		{
			if (*s == *accept)
			{
				sum++;
				break;
			}
			accept++;
		}
		if (sum > 0 && *accept == '\0')
		{
			return (sum);
		}
		s++;
	}
}
