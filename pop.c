#include "monty.h"

/**
 *pop - removes most top element
 *@line_number: line numbers in ds
 *@stack: double pointer to the head
 *Return: nothing
 */

void pop(stack_t **stack, unsigned int line_number)
{
	if (*stack != NULL)
	{
		stack_t *top = *stack;
		*stack = (*stack)->next;
		free(top)
		if (*stack)
			(*stack)->prev = NULL;
	}

	else
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
}

