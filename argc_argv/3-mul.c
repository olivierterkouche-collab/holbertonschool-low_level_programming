#include <stdio.h>
#include <stdlib.h>

/**
 * main - Multiply 2 given arguments together
 * @argc: Number of arguments
 * @argv: Array of string containing the program arguments
 *
 * Return: Returns 1 if the program fails or 0 if it executes
 * sucessfully
 */
int main(int argc __attribute__((unused)), char **argv)
{
	int arg1;
	int arg2;

	if (argv[1] == NULL || argv[2] == NULL)
	{
		printf("Error");
		return (1);
	}
	arg1 = atoi(argv[1]);
	arg2 = atoi(argv[2]);
	printf("%d\n", arg1 * arg2);
	return (0);
}
