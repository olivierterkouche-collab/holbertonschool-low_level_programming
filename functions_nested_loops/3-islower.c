#include "main.h"

/**
 * _islower - checks if c is a lowercase character
 * Return: Returns 1 if c is a lowercase character else returns 0
 */

int _islower(int c)
{
	if (c >= 97 && c <= 122)
	{
	return (1);
	}
	else
	{
	return (0);
	}
}
