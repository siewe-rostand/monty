#include "monty.h"

/**
 * _calloc - concatenate tw strings specially
 * @nmemb: number of elements
 * @size: type of elements
 * Return: nothing
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *p = NULL;
	unsigned int i;

	if (nmemb == 0 || size == 0)
	{
		return (NULL);
	}
	p = malloc(nmemb * size);
	if (p == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < (nmemb * size); i++)
	{
		*((char *)(p) + i) = 0;
	}
	return (p);
}

/**
 * _realloc - change the size and copy the content
 * @ptr: malloc pointer to reallocate
 * @old_size: old number of bytes
 * @new_size: new number of Bytes
 * Return: nothing
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p = NULL;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);
	if (ptr == NULL)
	{
		p = malloc(new_size);
		if (!p)
			return (NULL);
		return (p);
	}
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size > old_size)
	{
		p = malloc(new_size);
		if (!p)
			return (NULL);
		for (i = 0; i < old_size; i++)
			p[i] = *((char *)ptr + i);
		free(ptr);
	}
	else
	{
		p = malloc(new_size);
		if (!p)
			return (NULL);
		for (i = 0; i < new_size; i++)
			p[i] = *((char *)ptr + i);
		free(ptr);
	}
	return (p);
}
/**
 * get_operation_code - selects the correct opcode to perform
 *
 * @operation_code: operation code passed
 * @line_num: number of lines
 *
 * Return: pointer to the function that executes the opcode
 */
void (*get_operation_code(char *operation_code))(stack_t **stack,
		unsigned int line_num)
{
	instruction_t instruct[] = {
		{"push", _push_fun},
		{"pall", _print_all},
		{"pint", _print_int},
		{"pop", _pop_fun},
		{"swap", _swap_fun},
		{"queue", _queue_format},
		{"stack", _stack_format},
		{"add", _add_fun},
		{"nop", _nop},
		{"sub", _sub_fun},
		{"mul", _mul_fun},
		{"div", _div_fun},
		{"mod", _mod_fun},
		{"pchar", print_char},
		{"pstr", print_str},
		{"rotl", _rotate},
		{"rotr", _reverse},
		{NULL, NULL}
	};
	int i;

	for (i = 0; instruct[i].operation_code; i++)
	{
		if (_strcmp(instruct[i].operation_code, operation_code) == 0)
			break;
	}

	return (instruct[i].func);
}
