#include "main.h"

/**
 * add - adds two integers and prints the result
 * @x: first integer
 * @y: second integer
 *
 * Return: void
 */

int add(int x, int y)
{
int result = x + y;
int mod = result;
int sv = result;
int invrt = 0;
int mv;

while (sv >= 1)
{
	mv = sv % 10;
	invrt = invrt + mv;
	sv = sv / 10;
	if (sv >= 1)
	{
		invrt = invrt * 10;
	}
}
while (invrt >= 1)
{
	mod = invrt % 10;
	_putchar('0' + mod);
	invrt = invrt / 10;
}
return;
}
