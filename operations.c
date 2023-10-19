#include "monty.h"

/**
 * _pop_fun - removes the top element or node in stack
 *
 * @stack: head of the linked list
 * @line_num: number of lines
 * Return: nothing is return
 */
void _pop_fun(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		printf("L%d: can't pop an empty stack\n", line_num);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}


/**
 * push_func - pushes an element to the stack
 * @stack: stack
 * @line_number: line number
 */

void _push_fun(stack_t **stack, unsigned int line_num)
{
	stack_t *new = NULL;

	(void) line_num;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = global_var;
	new->prev = NULL;

	if (*stack == NULL)
	{
		new->next = NULL;
		*stack = new;
		return;
	}
	new->next = *stack;
	(*stack)->prev = new;
	*stack = new;
}
