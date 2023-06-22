#include "monty.h"

/**
 * free_stack - frees a stack_t stack
 * @stack: stack to be freed
 */

void free_stack(stack_t **stack)
{
	stack_t *current, *next;

	if (!stack)
		return;

	current = *stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
