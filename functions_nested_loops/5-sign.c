#include "main.h"

/**
 * print_sign - determinrs if given number is
 * positive negative or equal to zero
 * printing + - or 0 accordingly
 * @n: Represent a number we put trought
 * our function
 *
 * Return: Returns 1 -1 or 0 depending on the
 * value of n being positive negative or equal to 0
 */

int print_sign(int n)
{
if (n > 0)
{
	_putchar('+');
	return (1);
}
else if (n < 0)
{
	_putchar('-');
	return (-1);
}
else
{
	_putchar('0');
	return (0);
}
}
