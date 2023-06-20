#include "monty.h"

static void *g_memarray[MAX_MEMORY_CAPACITY];
static int g_memlen;

/**
 * alloc_mem - allicates memory on the heap and kerps track of it
 *
 * @size: the amount of bytes to allocate
 *
 * Return: an address to the allocated memory
 */
void *alloc_mem(unsigned long size)
{
	void *mem = malloc(size);
	int i;

	if (mem == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit_program(EXIT_FAILURE);
	}

	i = is_allocated(NULL);
	if (i != -1)
		g_memarray[i] = mem;

	if (i >= g_memlen)
		g_memlen = i + 1;

	return (mem);
}

/**
 * is_allocated - determines whether a value exists in the global memory array
 *
 * @mem: the value yo look for
 *
 * Return: the index of the value if found, -1 elsewise
 */
int is_allocated(const void *mem)
{
	int i;

	for (i = 0; i < g_memlen; i++)
		if (g_memarray[i] == mem)
			return (i);

	return (-1);
}

/**
 * free_mem - frees a memory address from the heap only it's if not freed yet
 *
 * @mem: the address to frer
 */
void free_mem(void *mem)
{
	int i = is_allocated(mem);

	if (i != -1)
	{
		free(mem);
		g_memarray[i] = NULL;
	}
}

/**
 * exit_program - frees all memory then exits the program
 *
 * @code: the exit code of the program
 */
void exit_program(int code)
{
	int i;

	for (i = 0; i < g_memlen; i++)
		if (g_memarray[i] != NULL)
		{
			free(g_memarray[i]);
			g_memarray[i] = NULL;
		}
	g_memlen = 0;

	exit(code);
}
