#include <stdio.h>
#include <stdlib.h>

/**
 * main - entry point / getline function
 * Return: 0
 */

int main(void)
{
	char *buffer;
	size_t size = 40;

	printf("$ ");

	buffer = malloc(sizeof(char) * size);
	if (buffer == NULL)
		perror("memory allocation failed");

	getline(&buffer, &size, stdin);
	
	printf("%s", buffer);

	return (0);

}
