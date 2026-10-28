#include "main.h"

/**
 * jack_bauer - Print the time from 00:00 to 23:59
 */

void jack_bauer(void)
{
int i = 0;
int j = 0;
int k = 0;
int l = 0;

while (i < 3)
{
	while (j < 10)
	{
		while (k < 6)
		{
			while (l < 10)
			{
			_putchar('0' + i);
			_putchar('0' + j);
			_putchar(':');
			_putchar('0' + k);
			_putchar('0' + l);
			_putchar('\n');
			l++;
			}
		l = 0;
		k++;
		}
	k = 0;
	j++;
	}
j = 0;
i++;
}
}
