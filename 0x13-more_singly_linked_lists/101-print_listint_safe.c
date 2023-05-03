#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_listint_safe - prints a listint_t linked list.
 * @head: pointer to the head of the linked list
 *
 * Return: number of nodes in the linked list
 */
size_t print_listint_safe(const listint_t *head)
{
    const listint_t *current, *temp;
    size_t count = 0;

    if (head == NULL)
        exit(98);

    current = head;
    while (current != NULL)
    {
        count++;
        printf("[%p] %d\n", (void *)current, current->n);
        current = current->next;
        temp = head;
        for (size_t i = 0; i < count; i++)
        {
            if (temp == current)
            {
                printf("-> [%p] %d\n", (void *)current, current->n);
                return (count);
            }
            temp = temp->next;
        }
    }
    return (count);
}
