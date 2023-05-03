#include "lists.h"
#include <stddef.h>
#include <stdio.h>

/**
 * find_listint_loop - Finds the loop in a linked list
 * @head: A pointer to the head of the linked list
 *
 * Return: The address of the node where the loop starts, or NULL if there is no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow, *fast;

	if (head == NULL)
		return (NULL);

	slow = head->next;
	fast = (head->next != NULL) ? head->next->next : NULL;

	while (fast != NULL && fast != slow)
	{
		slow = slow->next;
		fast = (fast->next != NULL) ? fast->next->next : NULL;
	}

	if (fast == NULL)
		return (NULL);

	slow = head;

	while (slow != fast)
	{
		slow = slow->next;
		fast = fast->next;
	}

	return (slow);
}
