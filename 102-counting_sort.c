#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order using
 *                 the Counting sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
 size_t i;
    /* Declare counting array and output array */
    int *counting_array;
    int *output_array;
    /* Find the maximum value in the array */
    int max = array[0];

   if (array == NULL || size < 2)
        return;
    for (i = 1; i < size; ++i)
    {
        if (array[i] > max)
            max = array[i];
    }


    /* Allocate memory for counting array */
    counting_array = malloc((max + 1) * sizeof(int));
    if (counting_array == NULL)
        return;

    /* Allocate memory for output array */
    output_array = malloc(size * sizeof(int));
    if (output_array == NULL)
    {
        free(counting_array);
        return;
    }

    /* Initialize counting array to 0 */
    for (i = 0; i <= (size_t)max; ++i)
        counting_array[i] = 0;

    /* Count the occurrences of each element in the original array */
    for (i = 0; i < size; ++i)
        counting_array[array[i]]++;

    /* Update the counting array to store the cumulative count */
    for (i = 1; i <= (size_t)max; ++i)
        counting_array[i] += counting_array[i - 1];

    /* Create the output array based on the counting array */
    for (i = size - 1; i != (size_t)-1; --i)
    {
        output_array[counting_array[array[i]] - 1] = array[i];
        counting_array[array[i]]--;
    }

    /* Copy the sorted array back to the original array */
    for (i = 0; i < size; ++i)
        array[i] = output_array[i];

    /* Print the counting array */
    print_array(counting_array, max + 1);

    /* Free allocated memory */
    free(counting_array);
    free(output_array);
}

