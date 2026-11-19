#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * print_numbers - Prints the strings given as parameters
 * @separator: String used to separate each number print
 * @n: Number of given parameters
 * @...: Variadic function indicator
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list arg;
    char *args;
	unsigned int i;

	va_start(arg, n);
	if (separator == NULL)
		separator = "";
	for (i = 0; i < n; i++)
	{
		args = va_arg(arg, char *);
		if (i == 0)
		{
			if (i == n - 1)
				printf("%s\n", args);
			else
				printf("%s", args);
		}
		else if (i < n - 1)
			printf("%s%s", separator, args);
		else
			printf("%s%s\n", separator, args);
	}
	if (n == 0)
		printf("\n");
	va_end(arg);
}
