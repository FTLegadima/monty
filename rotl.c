#include "monty.h"

/**
 * rotl - Rotates the stack to the top.
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: Line number in the Monty byte code file.
 */
void rotl(stack_t **stack, unsigned int line_number)
{
    stack_t *first, *last;

    (void)line_number;  // Unused parameter

    if (stack != NULL && *stack != NULL && (*stack)->next != NULL)
    {
        first = *stack;
        last = *stack;

        while (last->next != NULL)
            last = last->next;

        *stack = first->next;
        first->next = NULL;
        last->next = first;
        first->prev = last;
        (*stack)->prev = NULL;
    }
}
