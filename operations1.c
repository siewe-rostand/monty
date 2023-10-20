#include "monty.h"

/**
 * _queue_format - function to set queue (FIFO) format
 *
 * @stack: linked list head
 * @line_num: number of lines
 * Return: return nothing
 */
void _queue_format(stack_t **stack, unsigned int line_num)
{
	(void)stack;
	(void)line_num;

	vglo.lifo = 0;
}

/**
 * _stack_format - function to set the stack (LIFO) format
 *
 * @stack: linked list head
 * @line_num: number of lines
 * Return: return nothing
 */
void _stack_format(stack_t **stack, unsigned int line_num)
{
	(void)stack;
	(void)line_num;

	vglo.lifo = 1;
}


/**
 * _nop - doesn't do anythinhg
 *
 * @stack: linked list head
 * @line_num: number of lines
 * Return: no return
 */
void _nop(stack_t **stack, unsigned int line_num)
{
	(void)stack;
	(void)line_num;
}

/**
 * _isdigit - check digit @siewe-rostand
 *
 * @c: parameter
 *
 * Return: 1 if digit else 0
 */

int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
 * _swap_fun - function to swaps the top two elements of the stack
 *
 * @stack: linked list head
 * @line_num: number of lines
 * Return: return nothing
 */
void _swap_fun(stack_t **stack, unsigned int line_num)
{
	int m = 0;
	stack_t *tmp = NULL;

	tmp = *stack;

	for (; tmp != NULL; tmp = tmp->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", line_num);
		free_global_var();
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	tmp->prev = *stack;
	(*stack)->next = tmp;
	(*stack)->prev = NULL;
}
