#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * merge - Merges two sorted subarrays into a single sorted array.
 * @array: The array containing the subarrays to merge.
 * @left: The left index of the subarray.
 * @mid: The middle index where the array is split.
 * @right: The right index of the subarray.
 */
void merge(int *array, int left, int mid, int right)
{
    int i, j, k;
    int size_left = mid - left + 1;
    int size_right = right - mid;
    int *left_array = malloc(size_left * sizeof(int));
    int *right_array = malloc(size_right * sizeof(int));

    if (!left_array || !right_array)
        return;

    for (i = 0; i < size_left; i++)
        left_array[i] = array[left + i];
    for (j = 0; j < size_right; j++)
        right_array[j] = array[mid + 1 + j];

    printf("Merging...\n");
    printf("[left]: ");
    print_array(left_array, size_left);
    printf("[right]: ");
    print_array(right_array, size_right);

    i = 0;
    j = 0;
    k = left;

    while (i < size_left && j < size_right)
    {
        if (left_array[i] <= right_array[j])
        {
            array[k] = left_array[i];
            i++;
        }
        else
        {
            array[k] = right_array[j];
            j++;
        }
        k++;
    }

    while (i < size_left)
    {
        array[k] = left_array[i];
        i++;
        k++;
    }

    while (j < size_right)
    {
        array[k] = right_array[j];
        j++;
        k++;
    }

    printf("[Done]: ");
    print_array(array + left, right - left + 1);

    free(left_array);
    free(right_array);
}

/**
 * merge_sort_helper - Helper function to perform merge sort.
 * @array: The array to sort.
 * @left: The left index of the array to sort.
 * @right: The right index of the array to sort.
 */
void merge_sort_helper(int *array, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        merge_sort_helper(array, left, mid);
        merge_sort_helper(array, mid + 1, right);

        merge(array, left, mid, right);
    }
}

/**
 * merge_sort - Sorts an array of integers in ascending order using
 * the Merge sort algorithm.
 * @array: The array to sort.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    merge_sort_helper(array, 0, size - 1);
}
