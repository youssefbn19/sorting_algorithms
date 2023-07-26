#include "sort.h"
/**
 * shell_sort - sorts an array of integers in ascending order
 * using the Shell sort algorithm, using the Knuth sequence
 *
 * @array: array that we want to sort
 * @size: array size
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;
	int tmp;

	if (!array || size < 2)
		return;

	while ((gap * 3) + 1 <= size)
		gap = (gap * 3) + 1;

	while (gap >= 1)
	{
		for (i = gap; i < size; i++)
		{
			tmp = array[i];
			j = i;
			while (j >= gap && array[j - gap] > tmp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			if (i != j)
				array[j] = tmp;
		}
		print_array(array, size);
		gap /= 3;
	}
}
