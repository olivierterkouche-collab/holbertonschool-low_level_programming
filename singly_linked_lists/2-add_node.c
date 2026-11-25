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
	new->len = strlen(str);
	new->next = head;
	head = new;
	return (head);
}
