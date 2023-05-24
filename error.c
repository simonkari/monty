#include "monty.h"

/**
 * _error - manage the error
 * @stack: Pointer to the head of the stack.
 * @n: Integer value.
 */
void _error(stack_t **stack, unsigned int n)
{
    fprintf(stderr, "L%u: unknown instruction %s\n", n, global.line);
    free(global.line);
    fclose(global.fil);
    free_l(stack);
    if (stack != NULL)
    {
        *stack = NULL;
    }
    exit(EXIT_FAILURE);
}
