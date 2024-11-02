#include "sort.h"

/**
 * swap - Swaps two integers in an array.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void swap(int *a, int *b)
{
int temp = *a;
*a = *b;
*b = temp;
}

/**
 * partition - Partitions the array for quicksort using the Lomuto scheme.
 * @array: The array of integers.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition.
 * @size: The size of the array (for printing purposes).
 *
 * Return: The index of the pivot after partitioning.
 */
int partition(int *array, int low, int high, size_t size)
{
int pivot = array[high];
int i = low - 1;
int j;

for (j = low; j < high; j++)
{
if (array[j] < pivot)
{
i++;
if (i != j)
{
swap(&array[i], &array[j]);
print_array(array, size);
}
}
}

if (array[i + 1] != array[high])
{
swap(&array[i + 1], &array[high]);
print_array(array, size);
}
return (i + 1);
}

/**
 * quick_sort_recursive - Recursively sorts an array using quicksort.
 * @array: The array of integers.
 * @low: The starting index of the partition to sort.
 * @high: The ending index of the partition to sort.
 * @size: The size of the array.
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
if (low < high)
{
int pivot_index = partition(array, low, high, size);
quick_sort_recursive(array, low, pivot_index - 1, size);
quick_sort_recursive(array, pivot_index + 1, high, size);
}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using the
 *              Quick sort algorithm with Lomuto partition scheme.
 * @array: The array of integers to be sorted.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
if (!array || size < 2)
return;

quick_sort_recursive(array, 0, size - 1, size);
}
