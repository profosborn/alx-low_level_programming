#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts a new node at a given position
 * @head: A pointer to a pointer to the first node of the list
 * @idx: The index where the new node should be added
 * @n: The value to be stored in the new node
 *
 * Return: On success, the address of the new node, otherwise NULL.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
    listint_t *new_node, *temp;
    unsigned int i;

    if (head == NULL)
        return (NULL);

    if (idx == 0)
        return (add_nodeint(head, n));

    temp = *head;
    for (i = 0; i < idx - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL)
        return (NULL);

    new_node = malloc(sizeof(listint_t));
    if (new_node == NULL)
        return (NULL);

    new_node->n = n;
    new_node->next = temp->next;
    temp->next = new_node;

    return (new_node);
}
