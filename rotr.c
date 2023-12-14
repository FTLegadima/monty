#include "monty.h"

/**
 * rotr - Rotates the stack to the bottom.
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: Line number in the Monty byte code file.
 */
void rotr(stack_t **stack, unsigned int line_number)
{
    stack_t *first, *last;

    (void)line_number;  // Unused parameter

    if (stack != NULL && *stack != NULL && (*stack)->next != NULL)
    {
        first = *stack;
        last = *stack;

        while (last->next != NULL)
            last = last->next;

        last->prev->next = NULL;
        last->prev = NULL;
        last->next = first;
        first->prev = last;
        *stack = last;
    }
}
