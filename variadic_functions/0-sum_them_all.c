#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * sum_them_all - Gives the sum of all parameters
 * @n: Parametters count
 * @...: indictaor that this is a variadic function
 *
 * Return: Returns args the sum of our arguments
 */
int sum_them_all(const unsigned int n, ...)
{
	unsigned int i;
	int args = 0;
	va_list arg;

	va_start(arg, n);
	for (i = 0; i < n; i++)
	{
		args += va_arg(arg, int);
	}
	va_end(arg);
	return (args);
}
