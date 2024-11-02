#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * merge - Merges two halves of an array into a sorted array
 * @array: The original array being sorted
 * @left: The starting index of the left subarray
 * @mid: The ending index of the left subarray
 * @right: The ending index of the right subarray
 * @temp: Temporary array used for merging
 */
void merge(int *array, int left, int mid, int right, int *temp)
{
    int i = left, j = mid + 1, k = left;

    /* Output for merging */
    printf("Merging...\n[left]: ");
    print_array(array + left, mid - left + 1);
    printf("[right]: ");
    print_array(array + mid + 1, right - mid);

    /* Merge the two halves into temp */
    while (i <= mid && j <= right)
    {
        if (array[i] <= array[j])
            temp[k++] = array[i++];
        else
            temp[k++] = array[j++];
    }
    while (i <= mid)
        temp[k++] = array[i++];
    while (j <= right)
        temp[k++] = array[j++];

    /* Copy sorted data back into original array */
    for (i = left; i <= right; i++)
        array[i] = temp[i];

    /* Output after merging */
    printf("[Done]: ");
    print_array(array + left, right - left + 1);
}

/**
 * merge_sort_recursive - Recursively divides and merges the array
 * @array: Array to be sorted
 * @left: Left index of the subarray
 * @right: Right index of the subarray
 * @temp: Temporary array used for merging
 */
void merge_sort_recursive(int *array, int left, int right, int *temp)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        /* Sort the left half, then the right half */
        merge_sort_recursive(array, left, mid, temp);
        merge_sort_recursive(array, mid + 1, right, temp);

        /* Merge the sorted halves */
        merge(array, left, mid, right, temp);
    }
}

/**
 * merge_sort - Sorts an array of integers in ascending order using Merge sort
 * @array: Array to be sorted
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
    int *temp;

    if (!array || size < 2)
        return;

    /* Allocate a single temporary array for merging */
    temp = malloc(size * sizeof(int));
    if (!temp)
        return;

    /* Start the recursive merge sort */
    merge_sort_recursive(array, 0, size - 1, temp);

    /* Free the temporary array */
    free(temp);
}
