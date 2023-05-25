#include "monty.h"

/**
 * _pop -  This function removes the top element from the stack.
 * @stack: Represents the head of the stack.
 * @num_line: number line
 */

#include "monty.h"

/**
 * _pop - function removes the top element from the stack.
 * @stack: head
 * @num_line:  An integer value indicating the line number.
 */
void _pop(stack_t **stack, unsigned int num_line)
{
stack_t *temp;

temp = *stack;
if (temp == NULL)
{
dprintf(2, "L%d: can't pop an empty stack\n", num_line);
free(global.line);
fclose(global.fil);
free_l(stack);
exit(EXIT_FAILURE);
}
if ((*stack)->next)
{
*stack = temp->next;
(*stack)->prev = NULL;
free(temp);
}
else
free_l(stack);
}
