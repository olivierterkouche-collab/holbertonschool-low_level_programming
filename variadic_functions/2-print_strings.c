#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * print_strings - Prints the strings given as parameters
 * @separator: String used to separate each string print
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
		if (args == NULL)
		{
			args = "(nil)";
		}
		if (i != 0)
			printf("%s", separator);
		printf("%s", args);
	}
	printf("\n");
	va_end(arg);
}
