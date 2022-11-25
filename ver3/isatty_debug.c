#include <stdio.h>
#include <unistd.h>

int main(void)
{
	/* STDIN_FILENO --> (0) --> input */
	int std_in_indicator = isatty(0);

	if (std_in_indicator == 1)
		printf("$: ");
	else
		printf("Cannot accept user input \n");
	

	printf("Std_in: [%d]\n", isatty(0));
	printf("Stdout: [%d]\n", isatty(1));
	printf("Stderr: [%d]\n", isatty(2));

	/*  */
	/* if (isatty(STDOUT_FILENO)) */
	/* 	puts("Connected to a terminal"); */
	/* else */
	/* 	puts("Not connected to a terminal"); */
	return (0);
}
