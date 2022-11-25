#include <stdio.h>
#include "funcs.h"
#include "prototypes.h"

/**
 * main- Entry Point
 *
 * Return: Always (0)
 */
int main(void)
{
	char *buffer;
	char **args, **args_cpy;
	int status = 0;

	do {
		/* Print a promt */
		printf("$: ");

		/* Read Line and store in buffer */
		buffer = read_line();
		printf("Buffer received: [%s]\n", buffer);

		/* Tokenize */
		args = tokenize(buffer);

		/* Copy pointer address of initial args */
		args_cpy = args;

		/* Print Every Argument */
		while (*args)
		{
		printf("Args: [%s]\n", *args);
		args++;
		}

		/* Reset args pointer back to original */
		args = args_cpy;

		status = proc_exe(args);

	} while (status);

	return (0);
}
