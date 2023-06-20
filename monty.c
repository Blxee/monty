#define _GNU_SOURCE
#include "monty.h"

void execute_instruction(
	const instruction_t *instruction_list,
	unsigned long size, const char *cmd,
	stack_t **stack,
	unsigned int line_number)
{
	unsigned int i;

	for (i = 0; i < size; i++)
	{
		if (strcmp(instruction_list[i].opcode, cmd) == 0)
		{
			instruction_list[i].f(stack, line_number);
			return;
		}
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, cmd);
	exit_program(EXIT_FAILURE);
}

/**
 * main - entry point of the program
 *
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: EXIT_SUCCESS if successful, EXIT_FAILURE elsewise
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	instruction_t instruction_list[6];
	FILE *file;
	size_t line_alloc = 0, line_number = 0;
	ssize_t line_len;
	char *line = NULL, *cmd = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit_program(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit_program(EXIT_FAILURE);
	}

	ADD_INSTRUCTION(0, push);
	ADD_INSTRUCTION(1, pall);
	ADD_INSTRUCTION(2, pint);
	ADD_INSTRUCTION(3, pop);
	ADD_INSTRUCTION(4, swap);
	ADD_INSTRUCTION(5, add);

	while ((line_len = getline(&line, &line_alloc, file)))
	{
		line_number++;
		cmd = strtok(line, DELIMETER);
		if (cmd)
			execute_instruction(instruction_list,
				sizeof(instruction_list) / sizeof(instruction_t),
				cmd, &stack, line_number);
	}

	free(line);
	fclose(file);
	exit_program(EXIT_SUCCESS);
	return (0);
}
