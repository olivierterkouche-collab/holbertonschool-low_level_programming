#include "main.h"

/**
 * _abs - gives the absolute value of given int
 * @n: The int input we want the absolute value of
 *
 * Return: Returns n the absolute value of given int
 */

int _abs(int n)
{
if (n < 0)
{
	n = n * (-1);
}
return (n);
}
