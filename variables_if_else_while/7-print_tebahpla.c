#include <stdio.h>

/**
 * main - For loop that prints the alphabet in reverse and lowercase
 * then breaks to a new line
 * Return: Returns 0 if the code worked as intended
 */
int main(void)
{
	char i;

	for (i = 122; i >= 97; i--)
	{
	putchar(i);
		if(i == 97)
		{
		putchar(10);
		}
	}
	return (0);
}
