#include "monty.h"
/**
 * _mod - computes the rest of the division of the second
 * top element of the stack by the top element of the stack.
 * @stack:  Pointer to the head of the stack.
 * @num_line: Line number of the command.
 */

void _mod(stack_t **stack, unsigned int num_line)
{
	stack_t *temp1, *temp2;
	int remainder = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(2, "L%d: can't mod, stack too short\n", num_line);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", num_line);
		exit(EXIT_FAILURE);
	}

	temp2 = (*stack)->next;
	remainder = temp2->n % (*stack)->n;
	temp1 = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp1);
	(*stack)->n = remainder;
}