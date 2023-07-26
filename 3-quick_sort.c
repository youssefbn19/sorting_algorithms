#include "sort.h"
/**
 * partition - divides array into two partitions using Lumoto partition
 *
 * @array: array that we want to partite
 * @l_index: lower index
 * @h_index: higher index
 * @size: array size
 *
 * Return: The pivot index.
 */
int partition(int *array, int l_index, int h_index, size_t size)
{
	int swapper, j, i;

	i = l_index - 1;
	for (j = l_index; j < h_index; j++)
	{
		if (array[j] <= array[h_index])
		{
			if (++i != j)
			{
				swapper = array[i];
				array[i] = array[j];
				array[j] = swapper;
				print_array(array, size);
			}
		}
	}
	if (++i != h_index)
	{
		swapper = array[i];
		array[i] = array[h_index];
		array[h_index] = swapper;
		print_array(array, size);
	}

	return (i);
}
/**
 * quickSort - Sorts a portion of an array, divides it into partitions
 *
 * @array: array that we want to sort
 * @l_index: lower index
 * @h_index: higher index
 * @size: array size
 *
 */
void quickSort(int *array, int l_index, int h_index, size_t size)
{
	int p_index;

	if (l_index >= h_index || l_index < 0)
		return;

	p_index = partition(array, l_index, h_index, size);
	quickSort(array, l_index, p_index - 1, size);
	quickSort(array, p_index + 1, h_index, size);
}
/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm and Lumoto partition.
 *
 * @array: array that we want to sort
 * @size: array size
 *
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quickSort(array, 0, size - 1, size);
}
