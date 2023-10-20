#include "monty.h"

/**
 * _rotate - function to rotate between two elements
 *
 * @stack: linked list head
 * @line_num: number of lines
 * Return: return nothing
 */
void _rotate(stack_t **stack, unsigned int line_num)
{
	stack_t *temp1 = NULL;
	stack_t *temp2 = NULL;
	(void)line_num;

	if (*stack == NULL)
		return;

	if ((*stack)->next == NULL)
		return;

	temp1 = (*stack)->next;
	temp2 = *stack;

	for (; temp2->next != NULL; temp2 = temp2->next)
		;

	temp1->prev = NULL;
	temp2->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = temp2;
	*stack = temp1;
}



/**
 * _reverse - function to reverse elements in a stack
 *
 * @stack: linked list head
 * @line_num: number of lines
 * Return: return nothing
 */
void _reverse(stack_t **stack, unsigned int line_num)
{
	stack_t *temp = NULL;
	(void)line_num;

	if (*stack == NULL)
		return;

	if ((*stack)->next == NULL)
		return;

	temp = *stack;

	for (; temp->next != NULL; temp = temp->next)
		;

	temp->prev->next = NULL;
	temp->next = *stack;
	temp->prev = NULL;
	(*stack)->prev = temp;
	*stack = temp;
}

/**
 * _strcmp - Function that compares two strings.
 * @s1: type str compared
 * @s2: type str compared
 * Return: 0 if s1 and s2 are equals.
 *         another value if they are different
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i] && s1[i]; i++)
		;
	if (s1[i] > s2[i])
		return (1);
	if (s1[i] < s2[i])
		return (-1);
	return (0);
}

/**
 * _search_char - function to search for a char in string
 * @str: string containing the char
 * @ch: char to be find
 * Return: 1 if success 0 if not
 */
int _search_char(char *str, char ch)
{
	int counter = 0;

	while (str[counter] != '\0')
	{
		if (str[counter] == ch)
		{
			break;
		}
		counter++;
	}
	if (str[counter] == ch)
		return (1);
	else
		return (0);
}
