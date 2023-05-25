#include "monty.h"

/**
 * _add - adds the top two elements of the stack.
 * @stack: Pointer to the head of the stack.
 * @num_line: Line number of the command.
 */

void _add(stack_t **stack, unsigned int num_line)
{
    if (!(*stack) || !(*stack)->next)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", num_line);
        free(global.line);
        fclose(global.fil);
        free_l(stack);
        exit(EXIT_FAILURE);
    }

    stack_t *temp1 = *stack;
    stack_t *temp2 = (*stack)->next;

    int sum = temp1->n + temp2->n;
    temp2->n = sum;

    *stack = temp2;
    temp2->prev = NULL;

    free(temp1);
}