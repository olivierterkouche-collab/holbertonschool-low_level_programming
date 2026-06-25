#include "main.h"

/**
 * print_sign - prints a + if a number is positive a - if it's negative
 * or a 0 if it's equal to 0
 * @c: The value we are working on
 *
 * Return: Returns 1 if n is positive or negative and 0 if it equals 0
 */

int print_sign(int n)
{
	if (n > 0)
	{
	_putchar(43);
	return (1);
	}
	else if (n < 0)
	{
	_putchar(45);
	return (1);
	}
	else
	{
	_putchar(48);
	return (0);
	}
}
