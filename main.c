#include "monty.h"

/**
 * main - Entry point for the Monty interpreter.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line arguments.
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    FILE *monty_file = fopen(argv[1], "r");
    if (!monty_file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    stack_t *stack = NULL; // Initialize an empty stack

    parse_file(monty_file, &stack); // Implement this function to parse the Monty file

    fclose(monty_file);
    free_stack(&stack); // Implement this function to free the stack

    return EXIT_SUCCESS;
}
