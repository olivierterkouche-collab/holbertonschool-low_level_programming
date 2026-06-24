#include <stdio.h>

/**
 * main - Prints all decimal digits folowed by a coma and a space
 * Return: Returns 0 if code was executed correctly
 */

int main(void)
{
int i;

	for (i = 48; i <= 57; i++)
	{
		if (i < 57)
		{
		putchar(i);
		putchar(44);
		putchar(32);
		}
		else
		{
		putchar(i);
		putchar(10);
		}
	}
	return (0);
}
