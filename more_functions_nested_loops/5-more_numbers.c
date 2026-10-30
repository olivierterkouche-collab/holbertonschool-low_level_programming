#include "main.h"

/**
 * more_numbers - Prints numers from 0 to 14 ten times
 */
void more_numbers(void)
{
	int i = 0;
	int j;

	while (i < 10)
	{
		j = 0;
		while (j < 15)
		{
			if (j > 9)
			{
				_putchar('1');
			}
			_putchar('0' + (j % 10));
			j++;
		}
		i++;
		_putchar('\n');
	}
}
