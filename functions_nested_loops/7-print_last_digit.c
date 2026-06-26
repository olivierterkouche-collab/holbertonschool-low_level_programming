#include "main.h"

/**
 * print_last_digit - prints the last digit of the parametters input
 * @r: parameters input used in the function
 *
 * Return: Returns the value of r after it has been processed by the function
 */

int print_last_digit(int r)
{
	if (r < 0)
	{
	r = r * -1;
	}
r = r % 10;
_putchar(r + '0');
return (r);
}
