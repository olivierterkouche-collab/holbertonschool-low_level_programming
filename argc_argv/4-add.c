#include <stdio.h>
#include <stdlib.h>

/**
 * main - Adds all the program parameters together
 * @argc: Number of arguments
 * @argv: Array of string containing the program arguments
 *
 * Return: Returns 1 if an error occured 0 if the program
 * sucessfully executed
 */
int main(int argc, char **argv)
{
	int i;
	int sum = 0;

	for (i = 1; i < argc; i++)
	{
		if (atoi(argv[i]) == 0)
		{
			printf("Error\n");
			return (1);
		}
		sum += atoi(argv[i]);
	}
	printf("%d\n", sum);
	return (0);
}
