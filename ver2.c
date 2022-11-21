#include "shell.h"

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
	{
		while (strcmp(buffer, "exit") != 0)
		{
			printf("$: ");
			read = getline(&buffer, &size, stdin);
			buffer[read - 1] = '\0';
			printf("Entered Buffer: [%s]\n", buffer);
		}
	}
	return (0);
}
