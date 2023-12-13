#include "monty.h"

/**
 * mod - Computes the rest of the division of the second top element
 *       by the top element of the stack.
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: Line number in the Monty byte code file.
 */
void mod(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = *stack;
    if (temp->n == 0)
    {
        fprintf(stderr, "L%u: division by zero\n", line_number);
        exit(EXIT_FAILURE);
    }

    *stack = (*stack)->next;
    (*stack)->n %= temp->n;
    (*stack)->prev = NULL;

    free(temp);
}
