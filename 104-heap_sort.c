#include "sort.h"

/**
 * heapify - Heapify the array
 * @array: Array to be heapified
 * @size: Size of the array
 * @i: Index to start heapify from
 * @total_size: Total size of the array
 */
void heapify(int *array, size_t size, size_t i, size_t total_size)
{
    size_t largest = i;
    size_t left = 2 * i + 1;
    size_t right = 2 * i + 2;
    int temp;
    if (left < size && array[left] > array[largest])
        largest = left;

    if (right < size && array[right] > array[largest])
        largest = right;

    if (largest != i)
    {
        temp = array[i];
        array[i] = array[largest];
        array[largest] = temp;

        print_array(array, total_size);
        heapify(array, size, largest, total_size);
    }
}

/**
 * heap_sort - Heap sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
    size_t i;
    int temp;
    if (array == NULL || size < 2)
	    return;

    for (i = size / 2 - 1; i > 0; i--)
        heapify(array, size, i, size);

    for (i = size - 1; i > 0; i--)
    {
        temp = array[0];
        array[0] = array[i];
        array[i] = temp;

        print_array(array, size);
        heapify(array, i, 0, size);
    }
}

