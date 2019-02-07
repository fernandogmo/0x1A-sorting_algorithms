#include "sort.h"

/*
 *
 */

void swap(listint_t *node, int phase, listint_t **list)
{
	(void)phase;
	if (node->prev)
	{
		if (node->next)
			node->next->prev = node->prev;
		node->prev->next = node->next;
		node->next = node->prev;
		node->prev = node->prev->prev;
		node->next->prev = node;
		if (node->prev)
			node->prev->next = node;
		else
			*list = node;
		print_list(*list);
	}
}
