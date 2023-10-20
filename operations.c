#include "monty.h"

/**
 * _push_fun - add a new element to stack
 *
 * @stack: linked list head
 * @line_num: number of lines
 * Return: return nothing
 */
void _push_fun(stack_t **stack, unsigned int line_num)
{
	int n, j;

	if (!global_var.args)
	{
		dprintf(2, "L%u: ", line_num);
		dprintf(2, "usage: push integer\n");
		free_global_var();
		exit(EXIT_FAILURE);
	}

	for (j = 0; global_var.args[j] != '\0'; j++)
	{
		if (!_isdigit(glo_v.args[j]) && glo_v.args[j] != '-')
		{
			dprintf(2, "L%u: ", line_num);
			dprintf(2, "usage: push integer\n");
			free_global_var();
			exit(EXIT_FAILURE);
		}
	}

	n = atoi(global_var.args);

	if (global_var.lifo == 1)
		add_node(stack, n);
	else
		add_end(stack, n);
}

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
		free_global_var();
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}


/**
 *add_end - doubly link list add node at the end function
 *@start: linked list first position node
 *@store_data: data to store
 *Return: double linked list is return
 */
stack_t *add_end(stack_t **start, const int store_data)
{
	stack_t *temp, *aux;

	if (start == NULL)
		return (NULL);
	temp = malloc(sizeof(stack_t));
	if (!temp)
	{
		dprintf(2, "Error: malloc failed\n");
		free_global_var();
		exit(EXIT_FAILURE);
	}
	temp->n = store_data;
	/*Careful with the first time*/
	if (*start == NULL)
	{
		temp->next = *start;
		temp->prev = NULL;
		*start = temp;
		return (*start);
	}
	aux = *start;
	while (aux->next)
		aux = aux->next;
	temp->next = aux->next;
	temp->prev = aux;
	aux->next = temp;
	return (aux->next);
}



/**
 *add_node - function to add new node at the beginning
 *@start: linked list first position node
 *@store_data: data to store
 *Return: double linked list is return
 */
stack_t *add_node(stack_t **start, const int store_data)
{
	stack_t *temp;

	if (start == NULL)
		return (NULL);
	temp = malloc(sizeof(stack_t));
	if (!temp)
	{
		dprintf(2, "Error: malloc failed\n");
		free_global_var();
		exit(EXIT_FAILURE);
	}
	temp->n = store_data;
	/*Careful with the first time*/
	if (*start == NULL)
	{
		temp->next = *start;
		temp->prev = NULL;
		*start = temp;
		return (*start);
	}
	(*start)->prev = temp;
	temp->next = (*start);
	temp->prev = NULL;
	*start = temp;
	return (*start);
}

/**
 * free_double_list - frees the doubly linked list
 *
 * @stack: stack head
 * Return: no return
 */
void free_double_list(stack_t *stack)
{
	stack_t *tmp;

	while ((tmp = stack) != NULL)
	{
		stack = stack->next;
		free(tmp);
	}
}
