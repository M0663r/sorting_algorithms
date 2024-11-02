#include "sort.h"

/**
 * swap_nodes - Swap two adjacent nodes in a doubly linked list.
 * @list: Pointer to the head of the list.
 * @left: The left node to be swapped.
 * @right: The right node to be swapped.
 */
void swap_nodes(listint_t **list, listint_t *left, listint_t *right)
{
if (left->prev)
left->prev->next = right;
else
*list = right;

if (right->next)
right->next->prev = left;

left->next = right->next;
right->prev = left->prev;
left->prev = right;
right->next = left;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Cocktail shaker sort algorithm.
 * @list: Double pointer to the head of the list.
 */
void cocktail_sort_list(listint_t **list)
{
listint_t *current;
int swapped = 1;

if (!list || !*list || !(*list)->next)
return;

while (swapped)
{
swapped = 0;
current = *list;

while (current && current->next)
{
if (current->n > current->next->n)
{
swap_nodes(list, current, current->next);
print_list(*list);
swapped = 1;
}
else
current = current->next;
}

if (!swapped)
break;

swapped = 0;
current = current->prev;

while (current && current->prev)
{
if (current->n < current->prev->n)
{
swap_nodes(list, current->prev, current);
print_list(*list);
swapped = 1;
}
else
current = current->prev;
}
}
}
