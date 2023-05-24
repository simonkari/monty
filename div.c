#include "monty.h"
/**
 * _div -des the second top element of the stack
 * by the top element of the stack.
 * @stack: Pointer to the head of the stack.
 * @num_line: Line number of the command.
 */

void _div(stack_t **stack, unsigned int num_line)
{
    if (*stack == NULL || (*stack)->next == NULL)
    {
        _error(stack, num_line);
    }
    else if ((*stack)->n == 0)
    {
        fprintf(stderr, "L%u: division by zero\n", num_line);
        free(global.line);
        fclose(global.fil);
        free_l(stack);
        exit(EXIT_FAILURE);
    }
    else
    {
        stack_t *temp1 = *stack;
        stack_t *temp2 = temp1->next;
        int divi = temp2->n / temp1->n;
        
        temp2->n = divi;
        *stack = temp2;
        free(temp1);
    }
}