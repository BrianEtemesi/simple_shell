#include "shell.h"
#include "func_debug.h"

/**
 * main- Entry Point
 *
 * Return: Always (0)
 */
int main(void)
{
	char *buffer;
	size_t size = 40;

	/* Allocate space to buffer */
	buffer = malloc(sizeof(char) * BUFFSIZE);
	if (buffer == NULL)
	{
		perror("Error allocating size to buffer\n");
		return (1);
	}

	print_shell(buffer, size);

	return (0);
}
