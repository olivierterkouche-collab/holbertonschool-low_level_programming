#include "main.h"

/**
 * _isalpha - checks if c is a lowercase or an uppercase letter
 * @c: The character we wish to check
 *
 * Return: Returns 1 if c is a lowercase or an uppercase letter else returns 0
 */

int _isalpha(int c)
{
	if (c >= 97 && c <= 122)
	{
	return (1);
	}
	else if (c >= 65 && c <= 90)
	{
	return (1);
	}
	else
	{
	return (0);
	}
}
