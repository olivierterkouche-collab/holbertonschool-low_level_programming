#include "main"

/**
 * jack_bauer - Print the time from 00:00 to 23:59
 *
 * Return: Returns 0 when the program successfully ended
 */

int jack_bauer(void)
{
int i = 0;
int j = 0;
int k = 0;
int l = 0;

while (i < 3)
{
	while (j < 10 && (i != 2 && j != 3 && k != 5 && l != 9))
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
return (0);
}
