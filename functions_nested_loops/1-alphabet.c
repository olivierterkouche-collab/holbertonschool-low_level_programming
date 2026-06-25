#include "main.h"

/**
 * print_alphabet - Prints the alphabet then adds a new line
 * Return: Returns 0 if the fonction is executed correctly
 */

void print_alphabet(void)
{
char i;
	for (i = 97; i <= 122; i++)
	{
	_putchar(i);
		if (i == 122)
		{
		_putchar(10);
		}
	}
	return (0);
}
