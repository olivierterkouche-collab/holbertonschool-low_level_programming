#include <stdio.h>

/**
 * main - Prints all the hexadecimal digits
 * before breaking to a new line
 * Return: Returns 0 if to code is executed correctly
 */

int main(void)
{
char i;

	for (i = 48; i <= 57; i++)
	{
	putchar(i);
	}
	for (i = 97; i <= 102; i++)
	{
	putchar(i);
		if (i == 102)
		{
		putchar(10);
		}
	}
	return (0);
}
