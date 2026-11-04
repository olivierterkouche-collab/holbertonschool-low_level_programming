#include "main.h"

/**
 * _puts - Prints a given string
 * with a newline
 * @str: String to print
 */
void _puts(char *str)
{
	int i;

	for (i = 0; *str != '\0'; i++)
	{
		_putchar(*str);
		str++;
	}
	_putchar('\n');
}
