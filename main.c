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
	char **args;
	int status = 0;

	do {
		printf("$: ");
		buffer = read_line();
		args = tokenize(buffer);
		status = proc_exe(args);

	} while (status);

	return (0);
}
