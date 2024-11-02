#include "sort.h"
#include <stdlib.h>

/**
 * counting_sort - Sorts an array of integers in ascending order using the
 * Counting sort algorithm.
 * @array: Array to be sorted.
 * @size: Size of the array.
 */
void counting_sort(int *array, size_t size)
{
    int *count_array, *output_array;
    int max = 0;
    size_t i;

    if (!array || size < 2)
        return;

    /* Find the maximum element in the array */
    for (i = 0; i < size; i++)
        if (array[i] > max)
            max = array[i];

    /* Allocate memory for count_array and output_array */
    count_array = malloc((max + 1) * sizeof(int));
    output_array = malloc(size * sizeof(int));
    if (!count_array || !output_array)
    {
        free(count_array);
        free(output_array);
        return;
    }

    /* Initialize count_array with 0 */
    for (i = 0; i <= (size_t)max; i++)
        count_array[i] = 0;

    /* Store the count of each element in count_array */
    for (i = 0; i < size; i++)
        count_array[array[i]]++;

    /* Print the counting array after counting occurrences */
    print_array(count_array, max + 1);

    /* Update count_array to store cumulative counts */
    for (i = 1; i <= (size_t)max; i++)
        count_array[i] += count_array[i - 1];

    /* Build the sorted output array */
    for (i = size; i > 0; i--)
    {
        output_array[count_array[array[i - 1]] - 1] = array[i - 1];
        count_array[array[i - 1]]--;
    }

    /* Copy the sorted output array back into the original array */
    for (i = 0; i < size; i++)
        array[i] = output_array[i];

    /* Free allocated memory */
    free(count_array);
    free(output_array);
}
