#include <stdio.h>
#include <stdlib.h>
#include "function_pointers.h"

/**
 * print_name - Prints the char type input in different ways depending
 * the pointed function
 * @name: char input we print
 * @f: pointer to the function we use to print our input
 */
void print_name(char *name, void (*f)(char *))
{
	f(name);
}
