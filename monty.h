#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define MAX_MEMORY_CAPACITY 4096

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* MEM_UTILS */
void *alloc_mem(unsigned long size);
int is_allocated(const void *mem);
void free_mem(void *mem);
void exit_program(int code);
/* !MEM_UTILS */

#endif /* MONTY_H */
