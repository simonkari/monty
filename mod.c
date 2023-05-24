#include "monty.h"
/**
 * _mod - computes the rest of the division of the second
 * top element of the stack by the top element of the stack.
 * @stack:  Pointer to the head of the stack.
 * @num_line: Line number of the command.
 */

void _mod(stack_t **stack, unsigned int num_line)
{
    if (*stack == NULL || (*stack)->next == NULL)
    {
        dprintf(2, "L%d: can't mod, stack too short\n", num_line);
        free(global.line);
        fclose(global.fil);
        free_l(stack);
        exit(EXIT_FAILURE);
    }

    int divisor = (*stack)->n;
    int dividend = (*stack)->next->n;
    int remainder = dividend % divisor;

    (*stack)->next->n = remainder;

    stack_t *temp = *stack;
    *stack = (*stack)->next;
    free(temp);
}