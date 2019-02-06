#include "sort.h"

void swap(int *a, int *b, int *array, int size)
{
	int t = *a;
	static int count = 0, s = 0, *ptr = NULL; /* for printing  */

	if (!ptr)
		ptr = array, s = size;
	*a = *b;
	*b = t;
	printf("%d: ", ++count);
	print_array(ptr, s);
}

int partition(int *array, int lo, int hi)
{
	int i, j, pivot = array[hi];

	for (j = i = lo; j < hi; j++)
		if (array[j] <= pivot)
			swap(&array[i++], &array[j], array, hi + 1);
	if (1)
		swap(&array[i], &array[hi], array, hi + 1), puts("^outer");
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


/*void quick_sort(int *array, size_t size)
{
	int i, j;
	int pivot = array[size / 2];

	if (size < 2)
		return;
	for (i = 0, j = size - 1; ; i++, j--)
	{
		while (array[i] < pivot)
			i++;
		while (array[j] > pivot)
			j--;
		if (i < j)
		{
			int temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			print_array(array, size);
		}
		else
			break;
	}
	quick_sort(array, i);
	quick_sort(array + i, size - i);
}*/
