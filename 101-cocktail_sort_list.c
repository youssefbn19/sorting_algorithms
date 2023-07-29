#include "sort.h"
/**
 * node_swapper - Swaps two nodes
 *
 * @list: pointer to pointer point to the head of a double linked list
 * @current: pointer to pointer point to the first node that will be swapped
 * @cmp: pointer to pointer point to the second node that will be swapped
 *
 */
void node_swapper(listint_t **list, listint_t **current, listint_t **cmp)
{
	(*current)->next = (*cmp)->next;
	(*cmp)->prev = (*current)->prev;
	(*current)->prev = (*cmp);
	(*cmp)->next = (*current);
	if ((*cmp)->prev)
		(*cmp)->prev->next = (*cmp);
	else
		*list = *cmp;
	if ((*current)->next)
		(*current)->next->prev = (*current);

	print_list(*list);
}
/**
 * forward_sort - Sorts nodes start from head (left) to tail (right)
 *
 * @list: pointer to pointer point to the head of a double linked list
 * @current: pointer to pointer point to the first node that will be swapped
 * @cmp: pointer to pointer point to the second node that will be swapped
 *
 * Return: true if a swap happens, Otherwise false
 */
bool forward_sort(listint_t **list, listint_t **current, listint_t **cmp)
{
	bool swapped = false;

	while ((*cmp)->next)
	{
		if ((*current)->n > (*cmp)->n)
		{
			node_swapper(list, current, cmp);
			(*cmp) = (*current)->next;
			swapped = true;
		}
		else
		{
			(*current) = (*current)->next;
			(*cmp) = (*cmp)->next;
		}
	}
	return (swapped);
}
/**
 * backward_sort - Sorts nodes start from tail (right) to head (left)
 *
 * @list: pointer to pointer point to the head of a double linked list
 * @current: pointer to pointer point to the first node that will be swapped
 * @cmp: pointer to pointer point to the second node that will be swapped
 *
 * Return: true if a swap happens, Otherwise false
 */
bool backward_sort(listint_t **list, listint_t **current, listint_t **cmp)
{
	bool swapped = false;

	while ((*current))
	{
		if ((*current)->n > (*cmp)->n)
		{
			node_swapper(list, current, cmp);
			(*current) = (*cmp)->prev;
			swapped = true;
		}
		else
		{
			(*current) = (*current)->prev;
			(*cmp) = (*cmp)->prev;
		}
	}
	return (swapped);
}
/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in
 * ascending order using the Cocktail shaker sort algorithm
 *
 * @list: pointer to pointer point to double linked list header
 */
void cocktail_sort_list(listint_t **list)
{
	bool swapped = false;
	listint_t *current = NULL, *cmp = NULL;

	if (!list || !(*list) || !((*list)->next))
		return;
	do {
		current = *list;
		cmp = current->next;
		swapped = forward_sort(list, &current, &cmp);

		if (!swapped)
			break;
		else if (!(current->next))
		{
			current = current->prev;
			cmp = current->next;
		}

		swapped = backward_sort(list, &current, &cmp);

	} while (swapped);
}
