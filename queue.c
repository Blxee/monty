#include "monty.h"

/**
 * unqueue_stack - removes the element at the bottom of the queue
 *
 * @stack: the address of the stack
 *
 * Return: the value at the top of the stack
 */
int unqueue_stack(stack_t **stack)
{
	stack_t *tail;
	int n;

	if (stack == NULL || *stack == NULL)
		return (0);

	tail = *stack;
	while (tail->next != NULL)
		tail = tail->next;

	if (tail->prev != NULL)
		tail->prev->next = NULL;
	else
		*stack = NULL;

	n = tail->n;
	free_mem(tail);

	return (n);
}
