#include "lists.h"

/**
 * get_nodeint_at_index - Returns the nth node of a listint_t linked list.
 * @head: A pointer to the head node of the linked list.
 * @index: The index of the node to return.
 *
 * Return: If successful, the node at the index in the linked list.
 *         Otherwise, NULL.
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
    listint_t *node = head;
    unsigned int i = 0;

    while (node)
    {
        if (i == index)
            return (node);
        i++;
        node = node->next;
    }

    return (NULL);
}
