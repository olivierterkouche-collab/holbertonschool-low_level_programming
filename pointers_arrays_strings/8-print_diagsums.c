#include <stdio.h>

/**
 * print_diagsums - Prints the sum of the values
 * of the 2 diagonals of a square matrix
 * @a: the matrix
 * @size: the size of the matrix
 */
void print_diagsums(int *a, int size)
{
	int sum = 0;
	int sum2 = 0;
	int i;
	int j = size - 1;

	for (i = 0; i < size; i++)
	{
		sum += a[i * size + i];
		sum2 += a[i * size + (size - i - 1)]
	}
	printf("%d, %d", sum, sum2);
}
