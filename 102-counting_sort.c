#include "sort.h"
/**
 * dynamic_array - allocate memory location for an array of integers
 *
 * @size: array size
 *
 * Return: pointer to the array
 */
int *dynamic_array(size_t size)
{
	int *new_array = NULL;
	size_t i;

	new_array = malloc(sizeof(int) * size);

	if (new_array == NULL)
	{
		printf("Can't malloc");
		exit(1);
	}

	for (i = 0; i < size; i++)
		new_array[i] = 0;

	return (new_array);
}
/**
 * counting_sort - Sorts an array of integers in ascending order
 * using the Counting sort algorithm
 *
 * @array: array that we want to sort
 * @size: array size
 *
 */
void counting_sort(int *array, size_t size)
{
	int k, j;
	size_t i;
	int *key_array = NULL, *sort_array = NULL;

	if (!array || size < 2)
		return;

	k = array[0];
	for (i = 1; i < size; i++)
		if (array[i] > k)
			k = array[i];

	key_array = dynamic_array(k + 1);

	for (i = 0; i < size; i++)
		key_array[array[i]]++;
	for (j = 1; j <= k; j++)
		key_array[j] += key_array[j - 1];

	print_array(key_array, k + 1);

	sort_array = dynamic_array(size);
	for (i = 0; i < size; i++)
	{
		sort_array[key_array[array[i]] - 1] = array[i];
		key_array[array[i]]--;
	}

	for (i = 0; i < size; i++)
		array[i] = sort_array[i];

	free(sort_array);
	free(key_array);
}
