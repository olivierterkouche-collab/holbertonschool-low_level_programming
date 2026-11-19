#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * print_numbers - Prints the numbers given as parameters
 * @separator: String used to separate each number print
 * @n: Number of given parameters
 * @...: Variadic function indicator
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list arg;
	int args;
	unsigned int i;

	va_start(arg, n);
	if (separator == NULL)
		separator = "";
	for (i = 0; i < n; i++)
	{
		args = va_arg(arg, int);
		if (i == 0)
		{
			if (i == n - 1)
				printf("%d\n", args);
			else
				printf("%d", args);
		}
		else if (i < n - 1)
			printf("%s%d", separator, args);
		else
			printf("%s%d\n", separator, args);
	}
	va_end(arg);
}
