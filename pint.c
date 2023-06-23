#include "monty.h"

/**
 *pint - prints the value at the top of the stack
 *@line_number: line numbers in ds
 *@stack: double pointer to the head
 *Return: nothing
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack != NULL)
		printf("%d\n", (*stack)->n);

	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
}
