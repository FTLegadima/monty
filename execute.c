#include "monty.h"

/**
 * execute_opcode - Executes the specified opcode.
 * @opcode: The opcode to execute.
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: Line number in the Monty byte code file.
 */
void execute_opcode(char *opcode, stack_t **stack, unsigned int line_number)
{
    int i;
    instruction_t opcodes[] = {
        {"push", push},
        {"pall", pall},
        {"pint", pint},
        {"pop", pop},
        {"swap", swap},
        {"add", add},
        {"nop", nop},
        {"sub", sub},
        {"div", div},
        // Add more opcodes as needed
        {NULL, NULL} // This marks the end of the array
    };

    for (i = 0; opcodes[i].opcode != NULL; i++)
    {
        if (strcmp(opcode, opcodes[i].opcode) == 0)
        {
            opcodes[i].f(stack, line_number);
            return;
        }
    }

    fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
    exit(EXIT_FAILURE);
}
