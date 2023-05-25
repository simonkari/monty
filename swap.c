#include "monty.h"
/**
 * _swap - swaps the top two elements of the stack
 * @stack: Represents the head of the stack.
 * @num_line: An integer value indicating the line number.
 */

void _swap(stack_t **stack, unsigned int num_line)
{
stack_t *temp;

if (*stack && (*stack)->next)
{
temp = (*stack)->next;
if (temp == NULL)
{
exit(0);
}
(*stack)->next = temp->next;
(*stack)->prev = temp;
temp->next = *stack;
temp->prev = NULL;
*stack = temp;
}
else
{
dprintf(2, "L%u: can't swap, stack too short\n", num_line);
free(global.line);
fclose(global.fil);
free_l(stack);

exit(EXIT_FAILURE);
}
}
