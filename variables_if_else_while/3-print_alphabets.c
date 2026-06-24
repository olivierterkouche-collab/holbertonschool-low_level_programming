#include <stdio.h>

/**
 * main - for loops that print the alphabet in lower and uppercases
 * and then adds a new line
 * Return: Returns 0 if the code worked as intended
 */
int main(void)
{
	char i;

	for (i = 97; i <= 122; i++)
	{
	putchar(i);
	}
	for (i = 65; i <= 90; i++)
	{
	putchar(i);
		if (i == 90)
		{
		putchar(10);
		}
	}
	return (0);
}
