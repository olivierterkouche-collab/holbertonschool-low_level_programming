#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * print_all - prints all the given argument
 * @format: A string containing the formats of all arguments
 */
void print_all(const char * const format, ...)
{
	va_list arg;
	int i = 0;
	char *idnt = ", ";

	while (format == NULL)
	{
		printf("\n");
		return;
	}
	va_start(arg, format);
	while (format[i] != '\0')
	{
		if (format[i + 1] == '\0')
			idnt = "";
		switch (format[i])
		{
			case 'c':
				printf("%c%s", va_arg(arg, int), idnt);
				break;
			case 'i':
				printf("%d%s", va_arg(arg, int), idnt);
				break;
			case 'f':
				printf("%f%s", va_arg(arg, double), idnt);
				break;
			case 's':
				if (format[i] == NULL)
				{
					printf("(nil)");
					break;
				}
				printf("%s%s", va_arg(arg, char *), idnt);
				break;
			default:
				break;
		}
		i++;
	}
	printf("\n");
	va_end(arg);
}
