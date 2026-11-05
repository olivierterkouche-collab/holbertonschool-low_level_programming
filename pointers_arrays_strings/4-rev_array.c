#include "main.h"

/**
 * reverse_array - reverses an array
 * @a: The array we reverse
 * @n: size of the array
 */
void reverse_array(int *a, int n)
{
	int temp;
	int i;

	for (i = 0; i <= ((n - 1) / 2); i++)
	{
		temp = a[i];
		a[i] = a[(n - 1) - i];
		a[(n - 1) - i] = temp;
	}
}
