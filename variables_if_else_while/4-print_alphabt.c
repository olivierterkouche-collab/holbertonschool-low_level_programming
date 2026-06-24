#include <stdio.h>
/**
 * main - for loop to print the alphabet in lowercase without q and e
 * Return: returns 0 if the code works as planned
 */
int main(void)
{
	char i;

	for (i = 97; i <= 122; i++)
	{
		if (i == 113 || i == 101)
		{
		}
		else
		{
		putchar (i);
		}
	}
	return (0);
}
