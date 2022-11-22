#ifndef FUNC_H
#define FUNC_H

#include "shell.h"

/**
 * print_shell- Function that prints a shell to stdout
 *
 * Return: Nothing
 */

void print_shell(char *buffer, size_t size)
{
	int read = 0;
	while (strcmp(buffer, "exit") != 0)
	{
		printf("$: ");
		read = getline(&buffer, &size, stdin);
		buffer[read - 1] = '\0';
		printf("Entered Buffer: [%s]\n", buffer);
	}
}
#endif /* FUNC_H */
