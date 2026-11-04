#include "main.h"

/**
 * print_rev - Prints a string in reverse
 * @s: string to print in reverse
 */
void print_rev(char *s)
{
	int i;
	int j;
	int strilen = 0;

	for (i = 0; *s != '\0'; i++)
	{
		s++;
		strilen++;
	}
	s--;
	strilen--;
	for (j = strilen; j >= 0; j--)
	{
		_putchar(*s);
		if (j != 0)
		{
			s--;
		}
	}
	_putchar('\n');
}
