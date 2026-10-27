#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the alphabet in lower and upper case
 * folowed by a new line
 *
 * Return: Returns 0 when the program sucessfuly ended
 */

int main(void)
{
	int n;

	for (n = 97; n <= 122; n++)
	{
	putchar(n);
	}

	for (n = 65; n <= 90; n++)
	{
	putchar(n);
	}

	putchar(10);

	return (0);
}
