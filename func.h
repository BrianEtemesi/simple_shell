#ifndef FUNC_H
#define FUNC_H

#include "shell.h"

/**
 * proc_exec- A function that hanldes process execution
 *
 * Return: Nothing
 */

void proc_exec(char *buffer, char *cmd, char *argv[])
{
	pid_t child_proc;

	child_proc = fork();
	if (child_proc == -1)
	{
		perror("Error\n");
		exit(1);
	}
	/* If creation was successful, execute command */
	if (child_proc == 0)
	{
		if (execve(cmd, argv, NULL) == -1)
			printf("Error. Command [%s] not found\n", buffer);
	}
	/* Return to parent process */
	else
	{
		wait(NULL);
	}
}


/**
 * print_shell- Function that prints a shell to stdout
 *
 * Return: Nothing
 */

void print_shell(char *buffer, size_t size)
{
	int read = 0;
	char *cmd;
	char pathname[BUFFSIZE];

	while (strcmp(buffer, "exit") != 0)
	{
		strcpy(pathname, "/bin/");
		cmd = "";

		printf("$: ");
		read = getline(&buffer, &size, stdin);
		buffer[read - 1] = '\0';
		cmd = strcat(pathname, buffer);
		char *argv[] = {cmd, NULL, NULL};

		printf("Entered Buffer: [%s]\n", buffer);
		proc_exec(buffer, cmd, argv);	
	}
}
#endif /* FUNC_H */
