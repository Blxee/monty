#include "monty.h"

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
	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit_program(EXIT_FAILURE);
	}

	(void)argv;
	exit_program(EXIT_SUCCESS);
}
