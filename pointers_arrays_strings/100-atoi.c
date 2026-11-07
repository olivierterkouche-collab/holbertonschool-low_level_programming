#include "main.h"

/**
 * _atoi - search for the first number of
 * a string and determines if it is positive
 * or negative
 * @s: The string we search trought
 *
 * Return: Returns the found number as an int
 * if no number are found in the string
 * Retrun 0
 */
int _atoi(char *s)
{
	int negativesum = 0;
	int i;
	int nf = 0;
	int retval = 0;

	while (*s != '\0')
	{
		if (*s == '-' && nf == 0)
			negativesum++;
		else if (nf != 0 && (*s < '0' || *s > '9'))
		{
			if (negativesum % 2 != 1)
			{
				retval = retval * (-1);
			}
			return (retval);
		}
		else if (*s >= '0' && *s <= '9')
		{
			nf = 1;
			for (i = 48; i <= 57; i++)
			{
				if (*s == i)
					retval = retval * 10;
					retval = retval + ((i - 48) * -1);
			}
		}
		s++;
		if (*s == '\0' && nf != 0)
		{
			if (negativesum % 2 != 1)
			{
				retval = retval * (-1);
			}
			return (retval);
		}
	}
	return (0);
}
