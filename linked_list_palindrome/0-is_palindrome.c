#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
/**
 *  reverseList - will reverse the singly linkedlist
 * @temp: temp pointer
 * Return: listint_t
 */
listint_t *reverseList(listint_t *temp)
{
	listint_t *current = temp;
	listint_t *prevNode = NULL, *nextNode = NULL;

	while (current != NULL)
	{
		nextNode = current->next;
		current->next = prevNode;
		prevNode = current;
		current = nextNode;
	}
	return (prevNode);
}
/**
 * is_palindrome - check for palindrome
 * @head: pointer
 * Return: true or false
 */
int is_palindrome(listint_t **head)
{
	listint_t *p, *q, *first_start, *second_start;
		p = *head;
		q = *head;

		if (p->next == NULL)
			return (1);
		while (1)
		{
			p = p->next->next;
			if (p == NULL)
			{
				second_start = q->next;
				break;
			}
			if (p->next == NULL)
			{
				second_start = q->next->next;
				break;
			}
			q = q->next;
		}
		q->next = NULL;
		second_start = reverseList(second_start);
		first_start = *head;
		while (first_start != NULL && second_start != NULL)
		{
			if (first_start->n == second_start->n)
			{
				first_start = first_start->next;
				second_start = second_start->next;
				free(second_start);
			}
			else
			{
				return (0);
			}
		}
		free(q);
		free(p);
		return (1);
}
