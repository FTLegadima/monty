#include "monty.h"

/**
 * addnode - add node to the head stack
 * @head: head of the stack
 * @n: new_value
 * Return: no return
 */
void addnode(stack_t **head, int n)
{
    stack_t *new_node, *aux;

    // Save the current head to aux
    aux = *head;

    // Allocate memory for the new node
    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        // Print an error message and exit if malloc fails
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    // If the stack is not empty, update the previous pointer of the current head
    if (aux)
        aux->prev = new_node;

    // Set the data and pointers for the new node
    new_node->n = n;
    new_node->next = *head;
    new_node->prev = NULL;

    // Update the head of the stack to be the new node
    *head = new_node;
}
