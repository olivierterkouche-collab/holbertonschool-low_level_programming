#include <stdio.h>
#include <stdlib.h>
#include "3-calc.h"

/**
 * op_add - performs an addition on 2 given int
 * @a: first int
 * @b: second int
 *
 * Return: Returns the result of the operation
 */
int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - performs a substraction on 2 given int
 * @a: first int
 * @b: second int
 *
 * Return: Returns the result of the operation
 */
int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - multiplies int a by int b
 * @a: first int
 * @b: second int
 *
 * Return: Returns the result of the operation
 */
int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - divides int a by int b
 * @a: first int
 * @b: second int
 *
 * Return: Returns the result of the operation
 */
int op_div(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}
	return (a / b);
}

/**
 * op_mod - gives the rest of the division of int a by int b
 * @a: first int
 * @b: second int
 *
 * Return: Returns the result of the operation
 */
int op_mod(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}
	return (a % b);
}
