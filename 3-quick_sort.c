#include "sort.h"

int partition(int *array, int lo, int hi)
{
	int t, j, i, pivot;

	i = lo;
	printf("lo = %d, hi = %d\n", lo, hi);
	if (lo > hi) exit(1);
       	pivot = array[hi];
	for (j = lo; j <= hi - 1; j++)
	{
		printf("array[j] = %d, pivot = %d\n", array[j], pivot);
		if (array[j] <= pivot)
		{
			t = array[i];
			array[i] = array[j];
			array[j] = t;
			print_array(array, hi + 1);
			i++;
		}
	}
	t = array[i];
	array[i] = array[hi];
	array[hi] = t;
	return (i);
}

void q_sort(int *array, size_t size)
{
	int pivot = partition(array, 0, size - 1);

	q_sort(array, pivot);
	q_sort(array + pivot + 1, size - pivot - 1);
}


void quick_sort(int *array, size_t size)
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
}
