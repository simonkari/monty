#include "monty.h"

/**
 * _add - adds the top two elements of the stack.
 * @stack: Pointer to the head of the stack.
 * @num_line: Line number of the command.
 */

void _add(stack_t **stack, unsigned int num_line)
{
    if (*stack && (*stack)->next)
    {
        stack_t *temp1 = *stack;
        stack_t *temp2 = (*stack)->next;
        int sum = temp1->n + temp2->n;

        *stack = temp2->next;
        if (*stack)
            (*stack)->prev = NULL;

        free(temp1);
        free(temp2);

        stack_t *new_node = malloc(sizeof(stack_t));
        if (!new_node)
        {
            fprintf(stderr, "Error: malloc failed\n");
            free_l(stack);
            exit(EXIT_FAILURE);
        }

        new_node->n = sum;
        new_node->prev = NULL;
        if (*stack)
        {
            new_node->next = *stack;
            (*stack)->prev = new_node;
        }
        *stack = new_node;
    }
    else
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", num_line);
        free(global.line);
        fclose(global.fil);
        free_l(stack);
        exit(EXIT_FAILURE);
    }
}