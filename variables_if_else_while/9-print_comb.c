#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints all single digits folowed by a coma and a space
 *
 * Return: Returns 0 when program sucessfully ended
 */

int main(void)
{
	int n;

	for (n = 48; n <= 57; n++)
	{
		putchar(n);
		if (n != 57)
		{
			putchar(44);
			putchar(32);
		}
	}

	putchar(10);

	return (0);
}
