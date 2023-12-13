#include "monty.h"

/**
 * div - Divides the second top element of the stack by the top element.
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: Line number in the Monty byte code file.
 */
void div(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = *stack;
    if (temp->n == 0)
    {
        fprintf(stderr, "L%u: division by zero\n", line_number);
        exit(EXIT_FAILURE);
    }

    *stack = (*stack)->next;
    (*stack)->n /= temp->n;
    (*stack)->prev = NULL;

    free(temp);
}
