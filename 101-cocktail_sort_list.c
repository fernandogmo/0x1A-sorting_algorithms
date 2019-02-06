#include "sort.h"

/**
 *
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *temp = *list;
	int flag = 0;
	int flag2 = 0;

	while (temp)
	{
		if (temp->prev && temp->prev->n > temp->n)
		{
			if (temp->next)
				temp->next->prev = temp->prev;
			temp->prev->next = temp->next;
			temp->next = temp->prev;
			temp->prev = temp->prev->prev;
			temp->next->prev = temp;
			if (temp->prev)
				temp->prev->next = temp;
			else
				*list = temp;
			flag = 1;
			print_list(*list);
		}
		if (flag2 == 0 && temp->next)
			temp = temp->next;
		else if (flag2 == 1 && temp->prev)
			temp = temp->prev;
		if (flag == 0 && (temp->next == NULL || temp->prev == NULL))
			return;
		else if (flag == 1 && temp->next == NULL)
		{
			flag = 0;
			flag2 = 1;
		}
		else if (flag == 1 && temp->prev == NULL)
		{
			flag = 0;
			flag2 = 0;
		}
	}
}
