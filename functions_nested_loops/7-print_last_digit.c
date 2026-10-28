#include "main.h"

/**
 * print_last_digit - prints and returns
 * the last digit of input n
 * @n: input of type int we want to determine the last
 * digit of
 *
 * Return: Returns n as the last digit of the input
 */

int print_last_digit(int n)
{
if (n < 0)
{
	n = n % 10;
	n = n * (-1);
	_putchar('0' + n);
}
else
{
	n = n % 10;
	_putchar('0' + n);
}
return (n);
}
