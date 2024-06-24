#include "lists.h"


/**
 * check_cycle - check cycle in linked list
 * @list: linked list
 * Return: 0 if is a cycle else 1
 */

int check_cycle(listint_t *list)
{
	listint_t *lista;
	listint_t *listb;

	if (list == NULL)
		return (0);

	lista = list;
	listb = list->next;

	while (lista != NULL && listb != NULL && listb->next != NULL)
	{
		if (lista == listb)
			return (1);
		lista = lista->next;
		listb = listb->next->next;
	}
	return (0);
}
