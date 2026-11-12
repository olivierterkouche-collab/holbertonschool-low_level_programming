#ifndef DOG_H
#define DOG_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct dog - struct containing informations about a dog
 * @name: name of the dog
 * @age: age of the dog
 * @owner: name of the dog owner
 *
 * Description: struct made of 3 members all giving information about a dog
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

typdef struct dog
{
	char *name;
	float age;
	char *owner;
} dog_t;

void init_dog(struct dog *d, char *name, float age, char *owner);

void print_dog(struct dog *d);

#endif
