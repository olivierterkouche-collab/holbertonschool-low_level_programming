#include <stdio.h>
#include <stdlib.h>

/**
 * main - Prints all the arguments passed to our program name included
 * @argc: Number of arguments
 * @argv: Array of strings containing our arguments
 *
 * Return: Returns 0 after sucessfull execution of our program
 */
int main(int argc, char **argv)
{
	int i;

	for (i = 0, i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}
	return (0);
}
