#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * execute_opcode - executes an opcode
 * @opcode: opcode to execute
 * @instructions: array of instructions
 * @stack: double pointer to the head of the stack
 * @line_number: line number of the opcode being executed
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */

int execute_opcode(char *opcode, instruction_t *instructions,
stack_t **stack, unsigned int line_number)
{
	int i;

	for (i = 0; instructions[i].opcode; i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return (1);
		}
	}

	return (0);
}

/**
 * read_file - reads a file line by line
 * @filename: name of the file to read
 * @instructions: array of instructions
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */

int read_file(char *filename, instruction_t *instructions)
{
	FILE *file = fopen(filename, "r");
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;
	stack_t *stack = NULL;
	char *opcode;

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		return (EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;
		opcode = strtok(line, " \t\n$^&*()-+=[]{}\\|;:'\",.<>/?!");
		if (!opcode || opcode[0] == '#')
			continue;

		if (!execute_opcode(opcode, instructions, &stack, line_number))
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
			fclose(file);
			free(line);
			free_stack(&stack);
			return (EXIT_FAILURE);
		}
	}
	fclose(file);
	free(line);
	free_stack(&stack);
	return (EXIT_SUCCESS);
}

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */

int main(int argc, char *argv[])
{
	char *filename = argv[1];
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{NULL, NULL}
	};

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	return (read_file(filename, instructions));
}
