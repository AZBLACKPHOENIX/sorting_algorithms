#include "sort.h"

/**
 * swap - Swaps two integers in an array
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * lomuto_partition - Implements the Lomuto partition scheme
 * @array: The array to be partitioned
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 * @size: The size of the array
 *
 * Return: The pivot index after partitioning
 */
size_t lomuto_partition(int *array, size_t low, size_t high, size_t size)
{
    int pivot = array[high];
    size_t i = low;
    size_t j = 0;
    for (j = low; j < high; j++)
    {
        if (array[j] < pivot)
        {
            if (i != j)
            {
                swap(&array[i], &array[j]);
                print_array(array, size);
            }
            i++;
        }
    }

    if (array[high] < array[i])
    {
        swap(&array[i], &array[high]);
        print_array(array, size);
    }

    return i;
}

/**
 * quick_sort_recursive - Implements the recursive Quick Sort algorithm
 * @array: The array to be sorted
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 * @size: The size of the array
 */
void quick_sort_recursive(int *array, size_t low, size_t high, size_t size)
{
    if (low < high)
    {
        size_t pivot_idx = lomuto_partition(array, low, high, size);

        if (pivot_idx > 0)
            quick_sort_recursive(array, low, pivot_idx - 1, size);
        quick_sort_recursive(array, pivot_idx + 1, high, size);
    }
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 *              using the Quick sort algorithm (Lomuto partition scheme).
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quick_sort_recursive(array, 0, size - 1, size);
}

