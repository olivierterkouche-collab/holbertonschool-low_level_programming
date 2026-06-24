#include <stdio.h>
/**
 * main - prints digits from 0 to 9 ending with a line break
 * but this time using puchar instead of printf
 * Return: Returns the value 0 if the code is executed properly
 */
int main(void)
{
int i;

	for (i = 48; i <= 57; i++)
	{
	putchar(i);
		if (i == 57)
		{
		putchar(10);
		}
	}
	return (0);
}
