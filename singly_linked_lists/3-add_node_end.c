#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node_end - Adds a new node at the end of our chained list
 * @head: pointer to the head of our list
 * @str: String contained by our new node
 *
 * Return: Returns a pointer to our new node or NULL if malloc fails
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *cursor;
	list_t *new;

	cursor = *head;
	if (cursor == NULL)
	{
		new = malloc(sizeof(list_t));
		if (new == NULL)
			return (NULL);
		new->str = strdup(str);
		new->len = _strlen(str);
		new->next = NULL;
		*head = new;
		return (*head);
	}
	while (cursor->next != NULL)
	{
		cursor = cursor->next;
	}
	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);
	new->str = strdup(str);
	new->len = _strlen(str);
	new->next = NULL;
	cursor->next = new;
	return (new);
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
