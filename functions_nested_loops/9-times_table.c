#include "main.h"

/**
 * times_table - prints multiplication tables 1 to 9
 */

void times_table(void)
{
int i;
int j;
int mult;

for (i = 0; i < 10; i++)
{
	for (j = 0; j < 10; j++)
	{
		mult = i * j;
		if (mult > 9)
		{
			mult = mult / 10;
			_putchar('0' + mult);
			mult = i * j;
			mult = mult % 10;
		}
		else
		{
			_putchar(' ');
		}
		_putchar('0' + mult);
		if (j != 9)
		{
			_putchar(',');
			_putchar(' ');
		}
		else
		{
			_putchar('\n');
		}
	}
}
return;
}
