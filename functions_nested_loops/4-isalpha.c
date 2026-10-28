#include "main.h"

/**
 * _isalpha - Checks if a character is
 * an alphabetic upper or lowercase character
 * @c: A char we put trought our function
 *
 * Return: Returns 1 if c is an alphabetic
 * lower or upper case character else
 * returns 0
 */

int _isalpha(int c)
{
if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
{
	return (1);
}
else
{
	return (0);
}
}
