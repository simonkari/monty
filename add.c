#include "monty.h"

/**
 * _add - adds the top two elements of the stack.
 * @stack: Pointer to the head of the stack.
 * @num_line: Line number of the command.
 */


void _add(stack_t **stack, unsigned int num_line)
{
    if (*stack == NULL || (*stack)->next == NULL)
    {
        _error(stack, num_line);
    }
    else
    {
        stack_t *temp1 = *stack;
        stack_t *temp2 = temp1->next;
        int sum = temp1->n + temp2->n;
        
        temp2->n = sum;
        *stack = temp2;
        free(temp1);
    }
}

