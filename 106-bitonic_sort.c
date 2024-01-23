#include "sort.h"
#include <stdio.h>

void bitonic_recursive(int *array, size_t size, int dir);
void bitonic_merge(int *array, size_t size, int dir);
void bitonic_compare(int *array, size_t size, int dir);
void swap(int *a, int *b);

/**
 * bitonic_sort - sorts an array of integers in ascending order using
 * the Bitonic sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void bitonic_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    bitonic_recursive(array, size, 1);
}

/**
 * bitonic_recursive - recursive function to implement the bitonic sort
 * @array: array to be sorted
 * @size: size of the array
 * @dir: sorting direction (1: ascending, 0: descending)
 */
void bitonic_recursive(int *array, size_t size, int dir)
{
    size_t mid;

    if (size < 2)
        return;

    mid = size / 2;

    printf("Merging [%lu/%lu] (%s):\n", size, size, dir ? "UP" : "DOWN");
    print_array(array, size);

    bitonic_recursive(array, mid, 1);
    bitonic_recursive(array + mid, mid, 0);

    bitonic_merge(array, size, dir);
}

/**
 * bitonic_merge - merge function for the bitonic sort
 * @array: array to be sorted
 * @size: size of the array
 * @dir: sorting direction (1: ascending, 0: descending)
 */
void bitonic_merge(int *array, size_t size, int dir)
{
    size_t mid = size / 2;
   
    if (size < 2)
        return;

    bitonic_compare(array, mid, dir);

    bitonic_merge(array, mid, dir);
    bitonic_merge(array + mid, mid, dir);
}

/**
 * bitonic_compare - compares and swaps elements to implement bitonic sort
 * @array: array to be sorted
 * @size: size of the array
 * @dir: sorting direction (1: ascending, 0: descending)
 */
void bitonic_compare(int *array, size_t size, int dir)
{
    size_t mid = size / 2;
    size_t i;

    if (size < 2)
        return;

    for (i = 0; i < mid; i++)
    {
        if ((array[i] > array[i + mid]) == dir)
            swap(&array[i], &array[i + mid]);
    }
}

/**
 * swap - swaps two integers
 * @a: first integer
 * @b: second integer
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

