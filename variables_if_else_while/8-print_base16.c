#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints all decimal values of base 16
 *
 * Return: Returns 0 when the program sucessfully ended
 */

int main(void)
{
	int n;

	for (n = 48; n <= 57; n++)
	{
		putchar(n);
	}
	for (n = 97; n <= 102; n++)
	{
		putchar(n);
	}
	putchar(10);
	return (0);
}
