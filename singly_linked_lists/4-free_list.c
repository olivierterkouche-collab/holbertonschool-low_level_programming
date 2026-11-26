#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * free_list - frees a linked list
 * @head: pointer to the start of the list
 */
void free_list(list_t *head)
{
    list_t *cursor;
    list_t *temp;

    if (head == NULL)
    {
        return;
    }
    cursor = head;
    while (cursor != NULL)
    {
        temp = cursor;
        free(cursor->str);
        free(cursor);
        cursor = temp->next;
    }
}
