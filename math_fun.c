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

	for (; tmp != NULL; tmp = tmp->next, q++)
		;

	if (q < 2)
	{
		dprintf(2, "L%u: can't div, stack too short\n", line_num);
		free_global_var();
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", line_num);
		free_global_var();
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next;
	tmp->n /= (*stack)->n;
	_pop_fun(stack, line_num);
}


/**
 * _add_fun - function to add two node in stack
 *
 * @stack: linked list head
 * @line_num: number of lines
 * Return: return nothing
 */
void _add_fun(stack_t **stack, unsigned int line_num)
{
	int q = 0;
	stack_t *tmp = NULL;

	tmp = *stack;

	for (; tmp != NULL; tmp = tmp->next, q++)
		;

	if (q < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", line_num);
		free_global_var();
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next;
	tmp->n += (*stack)->n;
	_pop_fun(stack, line_num);
}

/**
 * _sub_fun - subtracts two node in stack
 *
 * @stack: linked list head
 * @line_num: number of lines
 * Return: nothing
 */
void _sub_fun(stack_t **stack, unsigned int line_num)
{
	int m = 0;
	stack_t *tmp = NULL;

	tmp = *stack;

	for (; tmp != NULL; tmp = tmp->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", line_num);
		free_global_var();
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next;
	tmp->n -= (*stack)->n;
	_pop_fun(stack, line_num);
}

/**
 * _mul_fun - multiplies two nodes in stack
 *
 * @stack: linked list head
 * @line_num: number of lines
 * Return: return nothing
 */
void _mul_fun(stack_t **stack, unsigned int line_num)
{
	int m = 0;
	stack_t *tmp = NULL;

	tmp = *stack;

	for (; tmp != NULL; tmp = tmp->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't mul, stack too short\n", line_num);
		free_global_var();
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next;
	tmp->n *= (*stack)->n;
	_pop_fun(stack, line_num);
}

/**
 * _mod_fun - get modulus between two stack node
 * by the top element of the stack
 *
 * @stack: linked list head
 * @line_num: number of lines
 * Return: return nothing
 */
void _mod_fun(stack_t **stack, unsigned int line_num)
{
	int m = 0;
	stack_t *tmp = NULL;

	tmp = *stack;

	for (; tmp != NULL; tmp = tmp->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't mod, stack too short\n", line_num);
		free_global_var();
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", line_num);
		free_global_var();
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next;
	tmp->n %= (*stack)->n;
	_pop_fun(stack, line_num);
}
