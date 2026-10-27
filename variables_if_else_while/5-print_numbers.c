#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints all digits of base 10 followed by a new line
 *
 * Return: Returns 0 when program sucessfuly ended
 */

int main(void)
{
	int n;

	for (n = 48; n <= 57; n++)
	{
		putchar(n);
	}
	putchar(10);
	return (0);
}
