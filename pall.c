#include "monty.h"

/**
 * _pall - This function prints all the values
 * on stack, starting from the top of the stack.
 * @stack: Represents the head of the stack.
 * @num_line: An integer value indicating the line number.
 */

void _pall(stack_t **stack, unsigned int num_line)
{
stack_t *temp;
temp = *stack;
if (num_line)
while (temp)
{
printf("%d\n", temp->n);
temp = temp->next;
}
}
