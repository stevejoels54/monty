#include "monty.h"

/**
* add - adds the top two elements of the stack
* @stack: double pointer to stack
* @line_number: line number of ds
* Return:  exit failure
**/

void add(stack_t **stack, unsigned int line_number)
{
	int sum;
	stack_t *current = *stack;

	if (!current || !current->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (current && current->next)
	{
		sum = current->n + current->next->n;
		current->next->n = sum;
		current = current->next->next;
	}

	pop(stack, line_number);
}
