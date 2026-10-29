#include "main.h"

/**
 * print_to_98 - prints numbers from n to 98
 * @n: the number to start counting from
 *
 * Return: void
 */
void print_to_98(int n)
{
int i;
int j;
int it;
int sv;
int invrt;
int mv;

if (n <= 98)
{
	for (i = n; i <= 98; i++)
	{
		sv = i;
		if (i < 0)
		{
			_putchar('-');
			sv = i * -1;
		}
		if (i == 0)
		{
		_putchar('0');
		}
	invrt = numinvert(sv);
	it = itnum(i);
	printinvert(it, invrt);
	indent(i);
	}
}
else
{
	for (i = n; i >= 98; i--)
	{
		sv = i;
		invrt = numinvert(sv);
		it = itnum(i);
		printinvert(it, invrt);
		indent(i);
	}
return;
}
}

int numinvert(int sv)
{
int invrt;
int mv;

invrt = 0;
while (sv != 0)
{
	mv = sv % 10;
	invrt = invrt + mv;
	sv = sv / 10;
	if (sv != 0)
	{
		invrt = invrt * 10;
	}
}
return (invrt);
}

int itnum(int i)
{
int it;

it = 0;
while (i != 0)
{
	i = i / 10;
	it++;
}
return (it);
}

void indent(int i)
{
if (i != 98)
{
	_putchar(',');
	_putchar(' ');
}
else
{
	_putchar('\n');
}
return;
}

void printinvert(int it, int invrt)
{
int mv;
int j;

for (j = 0; j < it; j++)
{
	mv = invrt % 10;
	_putchar('0' + mv);
	invrt = invrt / 10;
}
return;
}
