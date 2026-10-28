#include "main.h"

/**
 * _islower - determines if a character is lowercase or not
 * @c: Represent a char we put trought our function
 *
 * Return: Returns 1 if the character is indeed a lowercase
 * returns 0 otherwise
 */

int _islower(int c)
{
if (c >= 'a' && c <= 'z')
{
	return (1);
}
else
{
	return (0);
}
}
