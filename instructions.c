#include "monty.h"

/**
 * push - the "push" instruction implementation
 *
 * @stack: the main stack to operate on
 * @line_number: line number of the current instruction
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *arg;
	int i;

	arg = strtok(NULL, DELIMETER);

	if (arg == NULL || arg[0] == '\0')
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_number + 1);
		exit_program(EXIT_FAILURE);
	}

	for (i = 0; arg[i]; i++)
		if (!(('0' <= arg[i] && arg[i] <= '9')
					|| (i == 0 && arg[i] == '-')))
		{
			dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_number + 1);
			exit_program(EXIT_FAILURE);
		}

	push_stack(stack, atoi(arg));
}

/**
 * pall - the "pall" instruction implementation
 *
 * @stack: the main stack to operate on
 * @line_number: line number of the current instruction
 */
void pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	print_stack(*stack);
}
