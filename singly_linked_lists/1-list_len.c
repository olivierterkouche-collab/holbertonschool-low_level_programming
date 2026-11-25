#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * list_len - Count the number of elements in a chained list
 * @h: pointer to the head of the list
 *
 * Return: Returns the number of nodes in the list
 */
size_t list_len(const list_t *h)
{
	size_t n = 0;

	while (h != NULL)
	{
		h = h->next;
		n++;
	}
	return (n);
}
