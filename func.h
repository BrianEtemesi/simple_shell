#ifndef FUNC_H
#define FUNC_H

#include "shell.h"

/**
 * proc_exec- A function that hanldes process execution
 * @cmd: Command passed (e.g., bin/ls)
 * @argv: Argument Vector Array
 *
 * Return: Nothing
 */

void proc_exec(char *cmd, char *argv[])
{
	pid_t child_proc;
	int status;

	printf("Bash parent Process: [%d]\n", getppid());
	/* Check to see if we have exit */
	if (strcmp(cmd, "/bin/exit") == 0)
	{
		printf("User Terminated\n");
		exit(1);
	}
	child_proc = fork();
	/* If Child process is created successfully, proceed to execute */
	if (child_proc == 0)
	{
		printf("Child Process started: [%d]\n", getpid());
		if (execve(cmd, argv, NULL) == -1)
		{
			printf("Command Not Found\n");
			exit(EXIT_FAILURE);
		}
		sleep(1);
	}
	/* Handle error */
	else if (child_proc == -1)
	{
		perror("Error\n");
		exit(1);
	}
	/* Return to parent process */
	else
	{
		wait(&status);
		printf("Bash parent Process: [%d] and id [%d]\n", getppid(), child_proc);
	}
}


/**
 * print_shell- Function that prints a shell to stdout
 * @buffer: String in buffer
 * @size: Size to print to buffer using getline
 *
 * Return: Nothing
 */

void print_shell(char *buffer, size_t size)
{
	int read = 0;
	char pathname[BUFFSIZE], cmd[BUFFSIZE];
	char *argv[3];

	argv[0] = cmd;
	argv[1] = NULL;
	argv[2] = NULL;

	buffer = (char *)malloc(sizeof(char) * BUFFSIZE);

	while (strcmp(buffer, "exit") != 0)
	{
		printf("Entering while loop\n");
		/* Reset Pathname */
		strcpy(pathname, "/bin/");
		strcpy(cmd, "");

		printf("$: ");

		/* Read will return no. of bytes read. -1 if EOF */
		read = getline(&buffer, &size, stdin);

		/* Handle EOF or Ctrl + D */
		if (read == -1)
			exit(1);

		/* Remove newline read by getline ()*/
		buffer[read - 1] = '\0';

		/* Concatenate to get full command e.g., /bin/ls */
		strcpy(cmd, strcat(pathname, buffer));
		printf("command sent : [%s]\n", cmd);

		/* Execute process */
		printf("Proceeding to execute within while\n");
		proc_exec(cmd, argv);
		printf("Post Execution \n");
	}
}
#endif /* FUNC_H */
