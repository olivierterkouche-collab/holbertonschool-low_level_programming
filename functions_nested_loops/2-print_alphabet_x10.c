#include "main.h"

/**
 * print_alphabet_x10 - Prints the alphabet 10 times then line breaks
 */

void print_alphabet_x10(void)
{
char i;
char j;
i = 1;
	while (i <= 10)
	{
		for (j = 97; j <= 122; j++)
		{
		_putchar(j);
		}
	_putchar(10);
	i++;
	}
}
