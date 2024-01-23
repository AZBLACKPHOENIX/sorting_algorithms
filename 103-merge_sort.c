#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * merge - Merge function to merge two halves of an array
 * @array: Original array
 * @temp: Temporary array to store merged result
 * @left: Left index of the sub-array
 * @mid: Middle index of the sub-array
 * @right: Right index of the sub-array
 */
void merge(int *array, int *temp, size_t left, size_t mid, size_t right)
{
    size_t i = left, j = mid, k = left;

    printf("Merging...\n");
    printf("[left]: ");
    print_array(array + left, mid - left);
    printf("[right]: ");
    print_array(array + mid, right - mid);

    while (i < mid && j < right)
    {
        if (array[i] <= array[j])
            temp[k++] = array[i++];
        else
            temp[k++] = array[j++];
    }

    while (i < mid)
        temp[k++] = array[i++];

    while (j < right)
        temp[k++] = array[j++];

    for (i = left; i < right; i++)
        array[i] = temp[i];

    printf("[Done]: ");
    print_array(array + left, right - left);
}

/**
 * merge_sort_recursive - Recursive function to perform merge sort
 * @array: Original array
 * @temp: Temporary array to store merged result
 * @left: Left index of the sub-array
 * @right: Right index of the sub-array
 */
void merge_sort_recursive(int *array, int *temp, size_t left, size_t right)
{
size_t mid = 0;
    if (right - left > 1)
    {
     mid = (left + right) / 2;

        merge_sort_recursive(array, temp, left, mid);
        merge_sort_recursive(array, temp, mid, right);

        merge(array, temp, left, mid, right);
    }
}

/**
 * merge_sort - Merge sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
    int *temp;

    if (array == NULL || size < 2)
        return;

    temp = malloc(size * sizeof(int));
    if (temp == NULL)
        return;

    merge_sort_recursive(array, temp, 0, size);

    free(temp);
}

