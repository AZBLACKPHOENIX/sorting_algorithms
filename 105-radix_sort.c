#include "sort.h"
#include <stdlib.h>

/**
 * getMax - Get the maximum value in an array
 * @array: Array of integers
 * @size: Size of the array
 * Return: Maximum value
 */
int getMax(int *array, size_t size)
{
    int max = array[0];
    size_t i;

    for (i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    return (max);
}

/**
 * countingSort - Perform counting sort on an array based on the significant place
 * @array: Array of integers
 * @size: Size of the array
 * @exp: Exponent representing the significant place (1, 10, 100, ...)
 */
void countingSort(int *array, size_t size, int exp)
{
    const size_t RANGE = 10;
    int *output = malloc(sizeof(int) * size);
    int count[RANGE] = {0};
    size_t i;

    if (!output)
        return;

    for (i = 0; i < size; i++)
        count[(array[i] / exp) % 10]++;

    for (i = 1; i < RANGE; i++)
        count[i] += count[i - 1];

    for (i = size - 1; i < SIZE_MAX; i--)
    {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    for (i = 0; i < size; i++)
        array[i] = output[i];

    free(output);
}

/**
 * radix_sort - Sort an array of integers in ascending order using LSD Radix sort
 * @array: Array of integers
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
    int max = getMax(array, size);
    size_t exp;

    for (exp = 1; max / exp > 0; exp *= 10)
    {
        countingSort(array, size, exp);
        print_array(array, size);
    }
}

