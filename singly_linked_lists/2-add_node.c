#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node - Adds a new node at the begining of a chained list
 * @head: pointer to the head of the list
 * @str: string of our new node
 *
 * Return: Returns a pointer to the new head of our list
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new;

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);
	new->str = strdup(str);
	new->len = _strlen(str);
	new->next = *head;
	*head = new;
	return (*head);
}

/**
 * _strlen - counts the elements of a string
 * @s: a string we want to count the elements of
 *
 * Return: Returns strilen the value
 * containing the counted string elements
 */
int _strlen(const char *s)
{
	int i;
	int strilen = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		strilen++;
	}
	return (strilen);
}
