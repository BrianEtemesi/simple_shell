#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	int read;

	char *buffer;
	size_t size = 40; 

	printf("$: ");
	buffer = malloc(sizeof(char) * size);

	getline(&buffer, &size, stdin);

	printf("%s", buffer);
	/* while (getline(&buffer, &size, stdin) != -1) */
	/* { */
	/* 	printf("Buffer: %s\n", buffer); */
	/* } */
	return (0);
}
