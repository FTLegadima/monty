#include "monty.h"

/**
 * queue - Sets the format of the data to a queue (FIFO).
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: Line number in the Monty byte code file.
 */
void queue(stack_t **stack, unsigned int line_number)
{
    (void)line_number;  // Unused parameter

    if (stack != NULL && *stack != NULL)
    {
        while ((*stack)->next != NULL)
            *stack = (*stack)->next;
    }
}
