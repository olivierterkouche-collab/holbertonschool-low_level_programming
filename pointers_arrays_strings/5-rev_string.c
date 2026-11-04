#include "main.h"

/**
 * rev_string - reverse the elements of a string
 * @s: string to reverse
 */
void rev_string(char *s)
{
	int len = _strlen(s);
	char temp;
	int i;

	for (i = 0; i <= ((len - 1) / 2); i++)
	{
		temp = s[i]
		s[i] = s[(len - 1) - i]
		s[(len - 1) - i] = temp
	}
}

/**
 * _strlen - count the elements of a string
 * @s: string we count the elements of
 *
 * Return: Returns the number of elements
 */
int _strlen(char *s)
{
	int i;
	int strilen = 0;

	for (i = 0; *s != '\0'; i++)
	{
		s++;
		strilen++;
	}
	return (strilen);
}
