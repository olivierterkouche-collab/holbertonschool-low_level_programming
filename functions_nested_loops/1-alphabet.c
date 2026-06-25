#include "main.h"

/**
 * print_alphabet - Prints the alphabet then adds a new line
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
}
