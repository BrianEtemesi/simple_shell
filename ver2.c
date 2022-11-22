#include "shell.h"
#include "func.h"

/**
 * main- Entry Point
 *
 * Return: Always (0)
 */
int main(void)
{
	char *buffer;
	int read = 0;
	size_t size = 40;

	/* Allocate space to buffer */
	buffer = malloc(sizeof(char) * BUFFSIZE);

	/* Prompt user for input */
	printf("Enter Something: ");

	/* Get user's line */
	read = getline(&buffer, &size, stdin);
	if (strcmp(buffer, "exit") == 0)
		exit(1);
	else
		print_shell(buffer, size);	
	return (0);
}
