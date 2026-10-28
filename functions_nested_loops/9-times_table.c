#include "main.h"

/**
 * times_table - prints multiplication tables 1 to 9
 */

void times_table(void)
{
int i;
int j;
int mult;
int mod;
int div;

for (i = 0; i < 10; i++)
{
	for (j = 0; j < 10; j++)
	{
	mult = i * j;
	mod = mult % 10;
	div = mult / 10;
		if (mult > 9)
		{
			_putchar('0' + div);
		}
		else if (j != 0)
		{
			_putchar(' ');
		}
		_putchar('0' + mod);
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
