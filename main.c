#include "monty.h"


/**
 * free_global_var -free glo_v
 *
 * Return: nothing is return
 */
void free_global_var(void)
{
	free_double_list(global_var.head);
	free(global_var.input);
	fclose(global_var.file_des);
}

/**
 * start_global_var - initializes glo_v
 *
 * @file_des: file descriptor
 * Return: no return
 */
void start_global_var(FILE *file_des)
{
	global_var.lifo = 1;
	global_var.cline = 1;
	global_var.args = NULL;
	global_var.head = NULL;
	global_var.file_des = file_des;
	global_var.input = NULL;
}

/**
 * check_input - checks if the file exists and if the file can
 * be opened
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: file struct
 */
FILE *check_input(int argc, char *argv[])
{
	FILE *fd;

	if (argc == 1 || argc > 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");

	if (fd == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return (fd);
}

/**
 * main - Entry point
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	void (*f)(stack_t **stack, unsigned int line_number);
	FILE *fd;
	size_t size = 256;
	ssize_t nlines = 0;
	char *lines[2] = {NULL, NULL};

	fd = check_input(argc, argv);
	start_global_var(fd);
	nlines = get_line(&global_var.input, &size, fd);
	while (nlines != -1)
	{
		lines[0] = _strtok(global_var.input, " \t\n");
		if (lines[0] && lines[0][0] != '#')
		{
			f = get_opcodes(lines[0]);
			if (!f)
			{
				printf("L%d: ", global_var.cline);
				printf("unknown instruction %s\n", lines[0]);
				free_global_var();
				exit(EXIT_FAILURE);
			}
			global_var.args = _strtok(NULL, " \t\n");
			f(&global_var.head, global_var.cline);
		}
		nlines = get_line(&global_var.input, &size, fd);
		global_var.cline++;
	}

	free_global_var();

	return (0);
}

