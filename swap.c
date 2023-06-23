#include "monty.h"

/**
* swap - swaps value of the top two elements in a the stack
* @stack: double pointer to stack
* @line_number: line number of ds
* Return:  exit failure
**/

void swap(monty_stack_t **stack, unsigned int line_number)
{
	int temporary;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	else
	{
		temporary = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = temporary;
	}
}
