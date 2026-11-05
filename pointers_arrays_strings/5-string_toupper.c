#include "main.h"

/**
 * string_toupper - put lowercase characters of a
 * string to uppercase
 * @str: string we opperate on
 *
 * Return: Returns modified string
 */
char *string_toupper(char *str)
{
	int i;
	int j;
	int len = _strlen(str);

	for (i = 0; i < len; i++)
	{
		if (str[i] >= 97 && str[i] <= 122)
		{
			for (j = 97; j <= 122; j++)
			{
				if (str[i] == j)
				{
					str[i] -= 32;
				}
			}
		}
	}
	return (str);
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
