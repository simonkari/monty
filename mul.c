#include "monty.h"

/**
 * _mul - es the second top element of the stack with the
 * top element of the stack
 * @stack: Pointer to the head of the stack.
 * @num_line: Line number of the command.
 */

void _mul(stack_t **stack, unsigned int num_line)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(2, "L%u: can't mul, stack too short\n", num_line);
		exit(EXIT_FAILURE);
	}

	int multiplicand = (*stack)->next->n;
	int multiplier = (*stack)->n;
	int result = multiplicand * multiplier;

	stack_t *temp = *stack;
	*stack = (*stack)->next;
	if (*stack)
		(*stack)->prev = NULL;
	free(temp);

	(*stack)->n = result;
}