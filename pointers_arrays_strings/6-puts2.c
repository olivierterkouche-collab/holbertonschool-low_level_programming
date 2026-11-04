#include "main.h"

/**
 * puts2 - prints evry other characters of a string
 * @str: string we print every other character of
 */
void puts2(char *str)
{

	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (i == 0 || i % 2 == 0)
		{
			_putchar(str[i]);
		}
	}
	_putchar('\n');
}
