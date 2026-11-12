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
	unsigned int namelen;
	unsigned int ownerlen;

	doginfo = malloc(sizeof(dog_t));
	if (doginfo == NULL)
	{
		return (NULL);
	}
	namelen = _strlen(name);
	ownerlen = _strlen(owner);
	doginfo->name = malloc(namelen * sizeof(char) + 1);
	if (doginfo->name == NULL)
	{
		free(doginfo);
		return (NULL);
	}
	_strcpy(doginfo->name, name);
	doginfo->owner = malloc(ownerlen * sizeof(char) + 1);
	if (doginfo->owner == NULL)
	{
		free(doginfo->name);
		free(doginfo);
		return (NULL);
	}
	_strcpy(doginfo->owner, owner);
	doginfo->age = age;
	return (doginfo);
}

/**
 * _strcpy - copies a string to the buffer
 * @dest: pointer to the buffer
 * @src: pointer to the copied string
 *
 * Return: Returns the string copied in buffer
 */
char *_strcpy(char *dest, char *src)
{
	int len = _strlen(src);
	int i;

	for (i = 0; i <= len; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}

/**
 * _strlen - counts the elements of a string
 * @s: a string we want to count the elements of
 *
 * Return: Returns strilen the value
 * containing the counted string elements
 */
int _strlen(char *s)
{
	int i;
	int strilen = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		strilen++;
	}
	return (strilen);
}
