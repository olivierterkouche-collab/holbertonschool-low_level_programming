#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "3-calc.h"

/**
 * main - process the given arguments to do a given operation on them
 * @argc: Number of argument passed to the program counting program name
 * @argv: Array of strings containing the argument passed to our program
 *
 * Return: Returns 0 if the program executes correctly
 */
int main(int argc, char **argv)
{
	int val1 = atoi(argv[1]), val2 = atoi(argv[3]), res, i;
	op_t ope;

	for (i = 1; i < argc; i++)
	{
		if (argv[i] == NULL)
		{
			printf("Error\n");
			exit(98);
		}
	}
	ope.op = argv[2];
	ope.f = get_op_func(ope.op);
	if (ope.f == NULL)
	{
		printf("Error\n");
		exit(99);
	}
	res = ope.f(val1, val2);
	printf("%d\n", res);
	return (0);
}
