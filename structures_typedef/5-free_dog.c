#include <stdio.h>
#include <stdlib.h>
#include "dog.h"

/**
 * free_dog - frees allocated memory for a varriable of type dog_t
 * @d: dog_t varriable we free
 */
void free_dog(dog_t *d)
{
    free(d->owner);
    free(d->name);
    free(d);
}
