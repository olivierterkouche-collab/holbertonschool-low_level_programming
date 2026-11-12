#include <stdio.h>
#include <stdlib.h>
#include "dog.h"

/**
 * print_dog - prints the content of given variable of type struct dog
 * @d: varriable we print the content of
 */
void print_dog(struct dog *d)
{
	if (d == NULL)
	{
		return;
	}
	printf("Name: %s\n", d->name);
	printf("Age: %f\n", d->age);
	printf("Owner: %s\n", d->owner);
}
