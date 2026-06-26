#include "main.h"

/**
 * print_last_digit - prints the last digit of the parametters input
 * @r: parameters input used in the function
 *
 * Return: Returns the value of r after it has been processed by the function
 */

int print_last_digit(int r)
{
char a = r % 10;
	if (a < 0)
	{
	a = a * -1;
	}
_putchar(a + 48);
return (a);
}
