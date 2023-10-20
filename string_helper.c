#include "monty.h"

/**
 * print_char - print first element char
 *
 * @stack: linked list head
 * @line_num: number of lines
 * Return: return nothing
 */
void print_char(stack_t **stack, unsigned int line_num)
{
	if (stack == NULL || *stack == NULL)
	{
		dprintf(2, "L%u: can't pchar, stack empty\n", line_num);
		free_global_var();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n >= 128)
	{
		dprintf(2, "L%u: can't pchar, value out of range\n", line_num);
		free_global_var();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}

/**
 * print_str - prints the string of the stack
 *
 * @stack: linked list head
 * @line_num: number of lines
 * Return: return nothing
 */
void print_str(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;
	(void)line_num;

	tmp = *stack;

	while (tmp && tmp->n > 0 && tmp->n < 128)
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}

	printf("\n");
}

/**
 * _print_all - all stack value print function
 *
 * @stack: linked list head
 * @line_num: number of lines
 * Return: return nothing
 */
void _print_all(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;
	(void)line_num;

	tmp = *stack;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * _print_int - stack top value print function
 *
 * @stack: linked list head
 * @line_num: number of lines
 * Return: return nothing
 */
void _print_int(stack_t **stack, unsigned int line_num)
{
	(void)line_num;

	if (*stack == NULL)
	{
		dprintf(2, "L%u: ", line_num);
		dprintf(2, "can't pint, stack empty\n");
		free_global_var();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}


/**
 * _strtok - fstring tokenization
 * @str: string to cut in parts
 * @delimiter: delimiters
 * Return: first partition
 */
char *_strtok(char *str, char *delimiter)
{
	static char *token;
	int i = 0, j = 0;

	if (!str)
		str = token;
	while (str[i] != '\0')
	{
		if (_search_char(delimiter, str[i]) == 0 && str[i + 1] == '\0')
		{
			token = str + i + 1;
			*token = '\0';
			str = str + j;
			return (str);
		}
		else if (_search_char(delimiter, str[i]) == 0 &&
				_search_char(delimiter, str[i + 1]) == 0)
			i++;
		else if (_search_char(delimiter, str[i]) == 0 &&
				_search_char(delimiter, str[i + 1]) == 1)
		{
			token = str + i + 1;
			*token = '\0';
			token++;
			str = str + j;
			return (str);
		}
		else if (_search_char(delimiter, str[i]) == 1)
		{
			j++;
			i++;
		}
	}
	return (NULL);
}
