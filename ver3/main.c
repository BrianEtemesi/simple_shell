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
		if (isatty(0) == 1)
			printf("$: ");

		/* Read Line and store in buffer */
		buffer = read_line();
		printf("Buffer received: [%s]\n", buffer);

		/* Tokenize */
		args = tokenize(buffer);

		/* Copy pointer address of initial args */
		args_cpy = args;

		/* Check for exit */
		while (*args)
		{
			if (strcmp(*args, "exit") == 0)
				exit(0);
		args++;
		}
		/* Reset args pointer back to original */
		args = args_cpy;

		/* Check for status based on return of proc_exe() */
		if (proc_exe(args) == 0)
			status = 1;
		else
			status = 0;

		/* Print status*/
		printf("status is: [%d]\n", status);

	} while (status);

	return (0);
}
