#include "monty.h"

/**
 * mod - the "mod" instruction implementation
 *
 * @stack: the main stack to operate on
 * @line_number: line number of the current instruction
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int first, second;

	if (stack == NULL || *stack == NULL || len_stack(*stack) < 2)
	{
		fprintf(stderr,
				"L%u: can't mod, stack too short\n", line_number);
		exit_program(EXIT_FAILURE);
	}

	first = pop_stack(stack);
	second = pop_stack(stack);

	if (first == 0)
	{
		fprintf(stderr,
			"L%u: division by zero\n", line_number);
		exit_program(EXIT_FAILURE);
	}

	push_stack(stack, second % first);
}

/**
 * pchar - the "pchar" instruction implementation
 *
 * @stack: the main stack to operate on
 * @line_number: line number of the current instruction
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	int n;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr,
				"L%u: can't pchar, stack empty\n", line_number);
		exit_program(EXIT_FAILURE);
	}

	n = (*stack)->n;
	if (n < 0 || n > 127)
	{
		fprintf(stderr,
			"L%u: can't pchar, value out of range\n", line_number);
		exit_program(EXIT_FAILURE);
	}

	printf("%c\n", n);
}
