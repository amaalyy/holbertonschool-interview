#include "search.h"


/**
 * linear_skip - Function that searches for a value
 *		in a sorted skip list of integers
 * @list: Pointer to the head of the list
 * @value: Value to search for
 * Return: Pointer to the node containing the value or NULL if not found
 */

skiplist_t *linear_skip(skiplist_t *list, int value)
{

	skiplist_t *tmp = list;

	if (list == NULL)
		return (NULL);
	while (tmp->express != NULL)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		 tmp->express->index, tmp->express->n);
		if (tmp->express->n >= value)
		{
			printf("Value found between indexes [%lu] and [%ld]\n",
			 tmp->index, tmp->express->index);
			break;
		}
		tmp = tmp->express;
	}
	if (tmp->express == NULL)
	{
		for (list = tmp; list->next != NULL; list = list->next)
		;
		printf("Value found between indexes [%lu] and [%ld]\n",
		 tmp->index, list->index);
	}
	for (list = tmp ; list != tmp->express ; list = list->next)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		 list->index, list->n);
		if (value == list->n)
		{
			break;
		}
	}
	if (list == tmp->express)
		return (NULL);
	else
		return (list);
}
