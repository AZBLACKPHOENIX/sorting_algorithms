#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending order
 *                       using the Insertion sort algorithm.
 * @list: A pointer to the head of the doubly linked list.
 */
void insertion_sort_list(listint_t **list)
{
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    listint_t *current = (*list)->next, *insertion_point;

    while (current != NULL)
    {
        insertion_point = current->prev;

        while (insertion_point != NULL && insertion_point->n > current->n)
        {
            /* Swap the nodes */
            if (current->next != NULL)
                current->next->prev = insertion_point;

            insertion_point->next = current->next;
            current->prev = insertion_point->prev;
            current->next = insertion_point;
            insertion_point->prev = current;

            if (current->prev == NULL)
                *list = current;

            if (insertion_point->next != NULL)
                insertion_point->next->prev = insertion_point;

            insertion_point->next = (insertion_point->next == NULL) ? NULL : insertion_point->next;
            print_list(*list);
            insertion_point = current->prev;
        }

        current = current->next;
    }
}

