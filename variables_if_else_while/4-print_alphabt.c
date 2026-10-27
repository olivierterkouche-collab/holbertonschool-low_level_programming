#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the alphabet in lowercase omiting 'e' and 'q'
 * folowed by a newline
 *
 * Return: Returns 0 when program sucesfully ended
 */

int main(void)
{
	int n;

	for (n = 97; n <= 122; n++)
	{
		if (n != 101 && n != 113)
		{
		putchar(n);
		}
	}

	putchar(10);

	return (0);
}
