#ifndef MONTY
#define MONTY

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

#define BUFSIZE 1024

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct globals_v - the global variable structure
 * @lifo: is stack or queue
 * @cline: current line
 * @args: second parameter inside the current line
 * @head: list head
 * @file_des: description of file
 * @input: input
 *
 */
typedef struct globals
{
	int lifo;
	unsigned int cline;
	char  *args;
	stack_t *head;
	FILE *file_des;
	char *input;
} global_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern global_t global_var;
global_t global_var;

void _push_fun(stack_t **stack, unsigned int line_num);
void _print_all(stack_t **stack, unsigned int line_num);
void _print_int(stack_t **stack, unsigned int line_num);
void _pop_fun(stack_t **stack, unsigned int line_num);
void _swap_fun(stack_t **stack, unsigned int line_num);
void _queue_format(stack_t **stack, unsigned int line_num);
void _stack_format(stack_t **stack, unsigned int line_num);
void _add_fun(stack_t **stack, unsigned int line_num);
void _nop(stack_t **stack, unsigned int line_num);
void _sub_fun(stack_t **stack, unsigned int line_num);
void _div_fun(stack_t **stack, unsigned int line_num);
void _mul_fun(stack_t **stack, unsigned int line_num);
void _mod_fun(stack_t **stack, unsigned int line_num);
void print_char(stack_t **stack, unsigned int line_num);
void print_str(stack_t **stack, unsigned int line_num);
void _rotate(stack_t **stack, unsigned int line_num);
void _reverse(stack_t **stack, unsigned int line_num);

void (*get_opcodes(char *opc))(stack_t **stack, unsigned int line_number);

int _search_char(char *s, char c);
char *_strtok(char *s, char *d);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void *_calloc(unsigned int nmemb, unsigned int size);
int _strcmp(char *s1, char *s2);
int _isdigit(int c);


stack_t *add_end(stack_t **start, const int store_data);
stack_t *add_node(stack_t **start, const int store_data);
void free_double_list(stack_t *stack);

void free_global_var(void);
void bring_line(char **lineptr, size_t *n, char *buffer, size_t j);
ssize_t get_line(char **lineptr, size_t *n, FILE *stream);
char *_strcpy(char *dest, char *src);

#endif
