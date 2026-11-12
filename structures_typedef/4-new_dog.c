#include <stdio.h>
#include <stdlib.h>
#include "dog.h"

/**
 * new_dog - creates a new dog variable of type dog_t
 * @name: Name of the new dog
 * @age: Age of the new dog
 * @owner: Owner of the new dog
 *
 * Return: Returns a pointer to an initialized varriable of type dog_t
 * or null if function fails
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *doginfo;

	doginfo->name = *name;
	doginfo->age = age;
	doginfo->owner = *owner;
	if (doginfo == NULL)
	{
		return (NULL);
	}
	return (doginfo);
}
