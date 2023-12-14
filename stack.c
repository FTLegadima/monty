#include "monty.h"

/**
 * stack - Sets the format of the data to a stack (LIFO).
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: Line number in the Monty byte code file.
 */
void stack(stack_t **stack, unsigned int line_number)
{
    (void)line_number;  // Unused parameter

    if (stack != NULL && *stack != NULL)
    {
        while ((*stack)->prev != NULL)
            *stack = (*stack)->prev;
    }
}
