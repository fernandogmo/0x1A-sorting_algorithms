#include "sort.h"

/**
 *
 */

void new_cocktail_sort_list(listint_t **list)
{
	listint_t *temp = *list;
	int swapped = 0; /* if 2 elements have been swapped, this is set to 1 */
	int phase = 0; /* 0 for forward, 1 for backward */

	while (temp)
	{
		swapped = peek(temp, phase, list, swapped);
		if (!swapped && !phase && temp->next)
			temp = temp->next;
		else if (!swapped && phase && temp->prev)
			temp = temp->prev;
		if (!swapped && (!temp->next || !temp->prev))
			break;
		if (swapped && !temp->next)
		{
			swapped = 0;
			phase = 1;
		}
		else if (swapped && !temp->prev) 
		{
			swapped = 0;
			phase = 0;
		}
		/*printf("phase: %d, swapped: %d, temp: %d\n", phase, swapped, temp->n); this is an unhandled case */
	}
}
