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
	size_t count = 0;
	const listint_t *current, *check;

	current = head;

	while (current != NULL)
	{
		printf("[%p] %d\n", (void *)current, current->n);
		count++;

		current = current->next;
		check = head;
		while (check != current)
		{
			if (check == current->next)
			{
				printf("-> [%p] %d\n", (void *)current->next, current->next->n);
				return (count);
			}
			check = check->next;
		}
	}
	return (count);
}
