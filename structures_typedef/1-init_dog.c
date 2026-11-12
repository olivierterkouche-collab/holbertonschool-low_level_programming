#include <stdio.h>
#include <stdlib.h>
#include "dog.h"

/**
 * init_dog - initializes my_dog of type struct dog
 * @d: struct type and name
 * @name: struct argument 1
 * @age: struct argument 2
 * @owner: struct argument 3
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d == NULL)
	{
		return (1);
	}
	d->name = name;
	d->age = age;
	d->owner = owner;
}
