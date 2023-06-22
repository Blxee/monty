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

/**
 * pstr - the "pstr" instruction implementation
 *
 * @stack: the main stack to operate on
 * @line_number: line number of the current instruction
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	char *str;
	unsigned int i = 0, len = 0;
	stack_t *node;

	(void)line_number;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	len = len_stack(*stack);
	str = alloc_mem(len + 1);

	node = *stack;
	while (node->prev != NULL)
		node = node->prev;

	while (node)
	{
		if (node->n <= 0 || node->n > 127)
			break;
		str[i++] = node->n;
		node = node->next;
	}
	str[i] = '\0';

	printf("%s\n", str);
	free_mem(str);
}
