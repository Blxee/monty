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

	push_stack(stack, second % first);
}
