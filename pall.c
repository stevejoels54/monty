#include "monty.h"

/**
 * pall - prints all the values from stack, starting from the top
 * @stack: double pointer to the head of the stack
 * @line_number: line number of the opcode being executed
 */

void pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *current = *stack;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

