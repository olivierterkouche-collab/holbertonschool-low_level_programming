#include <stdio.h>
#include "main.h"

/**
 * print_array - prints the content of an array
 * separated with a coma and space
 * @a: the array we print the content of
 * @n: the size of the the array
 */
void print_array(int *a, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		if (i == n - 1)
		{
			printf("%d\n", a[i]);
		}
		else
		{
			printf("%d, ", a[i]);
		}
	}
}
