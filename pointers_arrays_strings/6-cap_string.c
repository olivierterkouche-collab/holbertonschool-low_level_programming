#include "main.h"

/**
 * cap_string - Capitilizes all words of a string
 * @str: The processed string
 *
 * Return: Retruns the processed string
 */
char *cap_string(char *str)
{
	int i;
	int j;
	int len = _strlen(str);
	char separators[14] = "' '	\n,;.!?\"(){}";

	for (i = 0; i < len; i++)
	{
		if (str[i] >= 97 && str[i] <= 122)
		{
			for (j = 0; j < 14; j++)
			{
				if (str[i - 1] == separators[j])
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
