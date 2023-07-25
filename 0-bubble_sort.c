#include "sort.h"
/**
* bubble_sort - sorts an array of integers in ascending order
* using the Bubble sort algorithm
*
* @array: array that we want to sort
* @size: array size
*/
void bubble_sort(int *array, size_t size)
{
	bool swap;
	size_t tmp, i, j;

	if (size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		swap = false;
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				swap =  true;
				print_array(array, size);
			}
		}
		if (!swap)
			break;
	}
}
