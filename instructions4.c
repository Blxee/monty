#include "monty.h"

/**
 * stack - the "stack" instruction implementation
 *
 * @stack: the main stack to operate on
 * @line_number: line number of the current instruction
 */
void stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	g_mode = STACK;
}

/**
 * queue - the "queue" instruction implementation
 *
 * @stack: the main stack to operate on
 * @line_number: line number of the current instruction
 */
void queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	g_mode = QUEUE;
}
