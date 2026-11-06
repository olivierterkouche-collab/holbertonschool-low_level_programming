#include "main.h"

/**
 * _strstr - Searchs a string for an other string matching
 * the sample given in a second string
 * @haystack: The string we search in
 * @needle: The sample we look for
 *
 * Return: Returns the pointer of the first character
 * of our matching sample in the string we look trought
 */
char *_strstr(char *haystack, char *needle)
{
	int i = 0;
	int j = 0;

	if (needle[i] == '\0')
	{
		return (&haystack[i]);
	}
	for (i = 0; haystack[i] != '\0'; i++)
	{
		if (haystack[i] == needle[j])
		{
			for (j = 0; needle[j] != '\0'; j++)
			{
				if (haystack[i] == needle[j])
				{
					i++;
					if (needle[j + 1] == '\0')
					{
						return (&haystack[i - (j + 1)]);
					}
				}
				else if (haystack[i] == '\0')
				{
					return (0);
				}
				else
				{
					break;
				}
			}
		j = 0;
		}
	}
	return (0);
}
