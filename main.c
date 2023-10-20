#include "monty.h"

/**
 * free_global_var -free glo_v
 *
 * Return: nothing is return
 */
void free_global_var(void)
{
	free_double_list(glo_v.head);
	free(glo_v.input);
	fclose(glo_v.file_des);
}

/**
 * start_global_var - initializes glo_v
 *
 * @file_des: file descriptor
 * Return: no return
 */
void start_global_var(FILE *file_des)
{
	glo_v.lifo = 1;
	glo_v.cline = 1;
	glo_v.args = NULL;
	glo_v.head = NULL;
	glo_v.file_des = file_des;
	glo_v.input = NULL;
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
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");

	if (fd == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
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
	nlines = getline(&glo_v.input, &size, fd);
	while (nlines != -1)
	{
		lines[0] = _strtok(glo_v.input, " \t\n");
		if (lines[0] && lines[0][0] != '#')
		{
			f = get_opcodes(lines[0]);
			if (!f)
			{
				dprintf(2, "L%u: ", glo_v.cline);
				dprintf(2, "unknown instruction %s\n", lines[0]);
				free_global_var();
				exit(EXIT_FAILURE);
			}
			glo_v.args = _strtok(NULL, " \t\n");
			f(&glo_v.head, glo_v.cline);
		}
		nlines = getline(&glo_v.input, &size, fd);
		glo_v.cline++;
	}

	free_global_var();

	return (0);
}

