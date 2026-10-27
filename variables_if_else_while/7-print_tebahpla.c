#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the alphabet in reverse and lowercase
 *
 * Return: Returns 0 when the program ends sucessfully
 */

int main(void)
{
	int n;
	for (n = 122; n >= 97; n--)
	{
		putchar(n);
	}

	putchar(10);

	return (0);
}
