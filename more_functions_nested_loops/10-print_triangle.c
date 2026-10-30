#include "main.h"

/**
 * print_triangle - prints a triangle
 * @size: defines the size of the triangle
 */
void print_triangle(int size)
{
	int i;
	int j;
	int k;
	int row = 1;

	if (size > 0)
	{
		for (i = 1; i <= size; i++)
		{
			for (j = 0; j < (size - row); j++)
			{
				_putchar(' ');
			}
			for (k = size; k > (size - row); k--)
			{
				_putchar('#');
			}
			_putchar('\n');
			row++;
		}
	}
	else
	{
		_putchar('\n');
	}
}
