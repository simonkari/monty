#include "monty.h"

/**
 * _mul - es the second top element of the stack with the
 * top element of the stack
 * @stack: Pointer to the head of the stack.
 * @num_line: Line number of the command.
 */

void _mul(stack_t **stack, unsigned int num_line)
{
stack_t *temp1;
stack_t *temp2;
int mult = 0;

if (*stack && (*stack)->next)
{
	temp2 = (*stack)->next;
	mult = temp2->n * (*stack)->n;
	temp1 = *stack;
	*stack = (*stack)->next;
	if (*stack)
			(*stack)->prev = NULL;
		free(temp1);
		(*stack)->n = mult;
	}
	else
	{
		dprintf(2, "L%u: can't mul, stack too short\n", num_line);
		free(global.line);
		fclose(global.fil);
		free_l(stack);
		exit(EXIT_FAILURE);
	}
}
