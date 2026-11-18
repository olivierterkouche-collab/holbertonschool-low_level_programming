#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the name of the program folowed by a newline
 * @argc: number of arguments in the program call
 * @argv: Array of strings containing each argument in the program call
 *
 * Return: Returns 0 when program was executed sucessfully
 */
int main(int argc, char **argv)
{
	printf("%s\n", argv[0]);
	return (0);
}
