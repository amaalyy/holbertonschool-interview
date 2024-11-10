#include "lists.h"
/**
 * find_listint_loop - Find the loop in a linked list
 * @head: A pointer to the head of the linked list.
 * Return: The address of the node where the loop
 * starts, or NULL if there is no loop.
 */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *start = head, *loop = head;

	while (loop && loop->next)
	{
		loop = loop->next->next;
		start = start->next;

		if (loop == start)
		{

			start = head;
			while (start != loop)
			{
				start = start->next;
				loop = loop->next;
			}
			return (loop);
		}
	}
	return (NULL);
}
