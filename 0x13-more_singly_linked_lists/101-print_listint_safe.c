#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * print_listint_safe - prints a linked list
 * @head: pointer to the head of the list
 * Return: the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
    const listint_t *tmp, *node;

    tmp = head;
    node = head;
    while (node && tmp && node->next)
    {
        node = node->next->next;
        tmp = tmp->next;
        if (node == tmp)
        {
            printf("[%p] %d\n", (void *)tmp, tmp->n);
            printf("-> [%p] %d\n", (void *)node->next, node->next->n);
            return (count_nodes(head, node));
        }
        printf("[%p] %d\n", (void *)tmp, tmp->n);
    }
    if (tmp)
    {
        printf("[%p] %d\n", (void *)tmp, tmp->n);
        tmp = tmp->next;
    }
    return (count_nodes(head, NULL));
}

/**
 * count_nodes - counts the number of nodes in a linked list
 * @head: pointer to the head of the list
 * @stop: pointer to the node where the loop was detected
 * Return: the number of nodes in the list
 */
size_t count_nodes(const listint_t *head, const listint_t *stop)
{
    const listint_t *node;
    size_t count = 0;

    node = head;
    while (node != stop)
    {
        count++;
        node = node->next;
    }
    if (stop)
        count++;
    return (count);
}
