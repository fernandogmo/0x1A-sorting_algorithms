#include "sort.h"

void swap(int *a, int *b, int *array, int size)
{
	int t = *a;
	static int s = 0, *ptr = NULL; /* for printing  */

	if (*a != *b)
	{
		*a = *b;
		*b = t;
		if (!ptr)
			ptr = array, s = size;
		print_array(ptr, s);
	}
}

int partition(int *array, int lo, int hi)
{
	int i, j, pivot = array[hi];

	for (j = i = lo; j < hi; j++)
		if (array[j] < pivot)
			swap(&array[i++], &array[j], array, hi + 1);
	swap(&array[i], &array[hi], array, hi + 1);
	return (i);
}

void quick_sort(int *array, size_t size)
{
	if (size > 2)
	{
		int pivot = partition(array, 0, size - 1);

		quick_sort(array, pivot);
		quick_sort(array + pivot + 1, size - pivot - 1);
	}
}
