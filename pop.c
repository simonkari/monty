#include "monty.h"
/**
 * _pop - removes the top element of stack
 * @stack: head
 * @num_line: number line
 */
void _pop(stack_t **stack, unsigned int num_line)
{
    if (*stack == NULL)
    {
        dprintf(2, "L%d: can't pop an empty stack\n", num_line);
        free(global.line);
        fclose(global.fil);
        free_l(stack);
        exit(EXIT_FAILURE);
    }

    stack_t *temp = *stack;
    *stack = (*stack)->next;
    if (*stack != NULL)
        (*stack)->prev = NULL;
    free(temp);
}