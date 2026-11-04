#include "main.h"

/**
 * puts_half - prints half a string rounded up
 * @str: string to print
 */
void puts_half(char *str)
{
	int i;
	int len;

	len = _strlen(str);
	if (len % 2 != 0)
	{
		len--;
	}
	else
	{
		len -= 2;
	}
	for (i = len / 2; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
	_putchar('\n');
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
