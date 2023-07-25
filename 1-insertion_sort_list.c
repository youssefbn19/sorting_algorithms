#include "sort.h"
/**
* insertion_sort_list - sorts a doubly linked list of integers in
* ascending order using the Insertion sort algorithm
*
* @list: pointer to pointer to the head of a double linked list
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL, *tmp = NULL;

	if (!list || !(*list) || !((*list)->next))
		return;

	current = (*list)->next;
	while (current)
	{
		tmp = current->prev;
		while (tmp && tmp->n > current->n)
		{
			if (tmp->n > current->n)
			{
				current->prev->next = current->next;
				if (current->next)
					current->next->prev = current->prev;
				if (*list == tmp)
					*list = current;
				else
					tmp->prev->next = current;
				current->next = tmp;
				current->prev = tmp->prev;
				tmp->prev = current;
				tmp = current->prev;
				print_list(*list);
			}
			else
				tmp = tmp->prev;
		}
		current = current->next;
	}
}
