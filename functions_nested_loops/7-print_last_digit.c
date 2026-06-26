#include "main.h"

/**
 * print_last_digit - prints the last digit of the parametters input
 * @r: parameters input used in the function
 *
 * Return: Returns the value of r after it has been processed by the function
 */

int print_last_digit(int r)
{
char a;
	if (r < 0)
	{
	a = r * -1;
	}
a = a % 10;
_putchar(a + 48);
return (a);
}
