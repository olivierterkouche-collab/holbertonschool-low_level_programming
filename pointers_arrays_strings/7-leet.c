#include "main.h"

/**
 * leet - replace defined characters by others
 * @str: string we opperate in
 *
 * Return: Returns the edited string
 */
char *leet(char *str)
{
	int i;
	int j;
	char rmp[11] = "aAeEoOtTlL";
	char rpl[6] = "43071";

	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; rmp[j] != '\0'; j++)
		{
			if (str[i] == rmp[j])
			{
				str[i] = rpl[j / 2];
			}
		}
	}
	return (str);
}
