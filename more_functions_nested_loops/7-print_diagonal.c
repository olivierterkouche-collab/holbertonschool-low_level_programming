#include "main.h"

/**
 * print_diagonal - prints a diagonal line
 * @n: lenght of the line
 */
void print_diagonal(int n)
{
	int i;
	int j;
	int row = 1;

	if (n > 0)
	{
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j < row; j++)
			{
				_putchar(' ');
			}
			_putchar('\\');
			_putchar('\n');
			row++;
		}
	}
	else
	{
		_putchar('\n');
	}
}
