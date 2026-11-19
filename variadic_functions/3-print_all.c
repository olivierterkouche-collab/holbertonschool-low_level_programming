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
	unsigned int i = 0;

	va_start(arg, format);
	while (format[i] != '\0')
	{
		switch (format[i])
		{
			case 'c':
			{
				char args = va_arg(arg, int);
				printf("%c", args);
				break;
			}
			case 'i':
			{
				int args = va_arg(arg, int);
				printf("%d", args);
				break;
			}
			case 'f':
			{
				float args = va_arg(arg, double);
				printf("%f", args);
				break;
			}
			case 's':
			{
				char *args = va_arg(arg, char *);
				if (args == NULL)
				{
					printf("(nil)");
					break;
				}
				printf("%s", args);
				break;
			}
			default:
				break;
		}
		if (format[i + 1] != '\0')
			printf(", ");
		i++;
	}
	printf("\n");
	va_end(arg);
}
