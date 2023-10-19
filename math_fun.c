#include "monty.h"

/**
 * _div_fun - divides the second element by the top element of the stack
 *
 * @stack: head of the linked list
 * @line_num: line number;
 * Return: no return
 */
void _div_fun(stack_t **stack, unsigned int line_num)
{
	int q = 0;
	stack_t *tmp = NULL;

	tmp = *stack;

	for (; tmp != NULL; tmp = tmp->next, m++)
		;

	if (q < 2)
	{
		dprintf(2, "L%u: can't div, stack too short\n", line_num);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", line_num);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next;
	tmp->n /= (*stack)->n;
	_pop_fun(stack, line_num);
}
