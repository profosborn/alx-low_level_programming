#include "lists.h"
#include <stddef.h>
#include <stdio.h>

/**
 * free_listint_safe - Frees a linked list safely
 * @h: A pointer to the head node of the linked list
 *
 * Return: The number of nodes freed
 */
size_t free_listint_safe(listint_t **h)
{
    size_t count = 0;
    listint_t *tmp, *head = *h;

    while (head != NULL)
    {
        count++;
        if (head <= head->next)
        {
            printf("-> [%p] %d\n", (void *)head, head->n);
            *h = NULL;
            break;
        }
        tmp = head;
        head = head->next;
        free(tmp);
    }
    return (count);
}
