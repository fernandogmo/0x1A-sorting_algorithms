#include "sort.h"

/*
 * 
 */

int peek(listint_t *node, int phase, listint_t **list, int swapped)
{
	if (phase)
	{
		if (node->prev->n > node->n && node->prev)
		{
			swap(node, phase, list);
			return (1);
		}
		node = node->prev;
	}
	else if (!phase)
	{
		if (node->n > node->next->n && node->next)
		{
			swap(node->next, phase, list);
			return (1);
		}
		node = node->next;
	}
	return (swapped);
}
