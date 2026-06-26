#include "main.h"

/**
 * _abs - Checks if the parametter is a positive number if not makes it one
 * @r: parametter we want to get the absolute value of
 *
 * Return: Returns the absolute value of the parameter
 */

int _abs(int r)
{
	if (r < 0)
	{
	r = r * -1;
	return (r);
	}
	else
	{
	return (r);
	}
}
