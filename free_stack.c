#include "monty.h"
/**
 * free_l - Frees a linked list.
 * @stack: Pointer to the head of the list.
 */

void free_l(stack_t **stack)
{
    stack_t *current = *stack;
    stack_t *next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    *stack = NULL;
}
