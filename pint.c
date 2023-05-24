#include "monty.h"
/**
 * _pint - prints the stack
 * @stack: head
 * @num_line: num line
 */
void _pint(stack_t *stack, unsigned int num_line)
{
    if (stack == NULL)
        return;
    if (stack->next == NULL)
    {
        printf("%d\n", stack->n);
        return;
    }
    _pint(stack->next, num_line);
}
