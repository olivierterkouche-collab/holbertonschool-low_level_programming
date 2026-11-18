#include <stdio.h>
#include <stdlib.h>

/**
 * main - Prints the number of arguments passed to the program
 * @argc: Number of argument passed to the program counting program name
 * @argv: Array of strings containing the argument passed to our program
 *
 * Return: Returns 0 after program sucessfull execution
 */
int main(int argc, char **argv __attribute__((unused)))
{
	printf("%d\n", argc - 1);
	return (0);
}
