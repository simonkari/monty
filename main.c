#include "monty.h"
globals_t global;
/**
 * main - The main entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the command-line arguments.
 * Return: An integer representing the exit status of the program.
 */

void _add(stack_t **stack, unsigned int num_line)
{
stack_t *temp1;
stack_t *temp2;
int sum = 0;

if (*stack && (*stack)->next)
{
temp2 = (*stack)->next;
sum = (*stack)->n + temp2->n;
temp1 = *stack;
*stack = (*stack)->next;
if (*stack)
		(*stack)->prev = NULL;
	free(temp1);
	(*stack)->n = sum;
}
else
{
	dprintf(2, "L%d: can't add, stack too short\n", num_line);
	free(global.line);
	fclose(global.fil);
	free_l(stack);
	exit(EXIT_FAILURE);
}
}