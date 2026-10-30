#include "main.h"

/**
 * more_numbers - Prints numers from 0 to 14 ten times
 */
void more_numbers(void)
{
	int i;
	int j;

	while (i < 10)
	{
		i = 0;
		while (j < 15)
		{
			if (j > 9)
			{
				_putchar('1');
			}
			_putchar('0' + (i % 10));
			i++
		}
		i++
		_putchar('\n');
	}
}
