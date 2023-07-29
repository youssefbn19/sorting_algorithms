#ifndef SORT_ALGO
#define SORT_ALGO
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
int partition(int *array, int l_index, int h_index, size_t size);
void quickSort(int *array, int l_index, int h_index, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void node_swapper(listint_t **list, listint_t **current, listint_t **cmp);
bool backward_sort(listint_t **list, listint_t **current, listint_t **cmp);
bool forward_sort(listint_t **list, listint_t **current, listint_t **cmp);
void counting_sort(int *array, size_t size);
int *dynamic_array(size_t size);
#endif
