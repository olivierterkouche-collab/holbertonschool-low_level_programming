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
	putchar(i);
	putchar(32);
	putchar(44);
		if (i == 57)
		{
		putchar(10);
		}
	}
	return (0);
}
