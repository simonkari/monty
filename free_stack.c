#include "monty.h"
/**
 * free_l - Frees a linked list.
 * @stack: Pointer to the head of the list.
 */

void free_l(stack_t **stack)
{
stack_t *delete = *stack;

while (*stack)
{
delete = delete->next;
free(*stack);
*stack = delete;
}
}
