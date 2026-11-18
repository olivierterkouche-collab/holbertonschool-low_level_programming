#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the name of the program folowed by a newline
 * @argv: Array of strings containing each argument in the program call
 *
 * Return: Returns 0 when program was executed sucessfully
 */
int main(int argc, char **argv)
{
	argc = argc - 1;
	printf("%s\n", argv[argc]);
	return (0);
}
