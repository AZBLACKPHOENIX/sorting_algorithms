#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending order
 *                      using the Cocktail shaker sort algorithm.
 * @list: A pointer to the head of the doubly linked list.
 */
void cocktail_sort_list(listint_t **list)
{
    int swapped;
    listint_t *current;

    if (list == NULL || *list == NULL)
        return;

    do {
        swapped = 0;
        for (current = *list; current->next != NULL; current = current->next)
        {
            if (current->n > current->next->n)
            {
                swap_nodes(list, &current, &current->next);
                swapped = 1;
                print_list(*list);
            }
        }

        if (!swapped)
            break;

        swapped = 0;
        for (; current->prev != NULL; current = current->prev)
        {
            if (current->n < current->prev->n)
            {
                swap_nodes(list, &current->prev, &current);
                swapped = 1;
                print_list(*list);
            }
        }
    } while (swapped);
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 * @list: A pointer to the head of the doubly linked list.
 * @a: The first node to swap.
 * @b: The second node to swap.
 */
void swap_nodes(listint_t **list, listint_t **a, listint_t **b)
{
    listint_t *temp;

    if (*a == NULL || *b == NULL)
        return;

    if ((*a)->prev != NULL)
        (*a)->prev->next = *b;
    else
        *list = *b;

    if ((*b)->next != NULL)
        (*b)->next->prev = *a;

    temp = (*b)->next;
    (*b)->next = *a;
    (*a)->next = temp;
    (*a)->prev = *b;
    (*b)->prev = (*a)->prev;
}
