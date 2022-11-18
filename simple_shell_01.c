#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFSIZE 1024

int main(void)
{
	char *buffer, *cmd; 
	size_t size = 40; 
	char pathname[BUFFSIZE];
	int status, read = 0; 
	pid_t child_proc;
	pid_t parent_proc;


	buffer = malloc(sizeof(char) * BUFFSIZE);

	while (1)
	{
		/* Reset pathname and cmd */
		strcpy(pathname, "/bin/");
		cmd = "";	

		/* Start Shell */
		printf("$: ");
		read = getline(&buffer, &size, stdin);
		buffer[read - 1] = '\0'; 
		cmd = strcat(pathname, buffer);

		char *argv[] = {cmd, NULL, NULL};

		/* Create the child process */
		child_proc = fork();

		/* Check if child process was successful */
		if (child_proc == -1)
		{
			perror("Error: Cannot Run Command.\n");
			exit(1);
		}

		/* If child process is successful, execute command */
		if (child_proc == 0)
		{
			if(execve(argv[0], argv, NULL) == -1)
			{
				printf("Command Not Found\n");
				exit(1);
			}
		}

		/* Return to parent process */
		else
		{
			wait(NULL);
			if (strcmp(buffer, "exit") == 0)
			{
				printf("User Terminated\n");
				exit(1);
			}
		}
	}
	free(buffer);
	return (0);
}
