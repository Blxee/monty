#include "monty.h"

/**
 * queue_stack - queues an element at the top of the stack
 *
 * @stack: the address of the stack
 * @n: the new element
 *
 * Return: the address of the new node
 */
stack_t *queue_stack(stack_t **stack, int n)
{
	stack_t *new, *prev = NULL;

	if (stack == NULL)
		return (NULL);

	while (*stack != NULL)
	{
		prev = *stack;
		stack = &(*stack)->next;
	}

	new = alloc_mem(sizeof(stack_t));
	new->n = n;
	new->prev = prev;
	new->next = NULL;

	*stack = new;

	return (new);
}

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
