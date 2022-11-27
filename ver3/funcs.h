#ifndef FUNCS_H
#define FUNCS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFSIZE 1024
#define TOK_DELIM " \t\r\n\a"

/**
 * read_line- Function that reads user input and handles EOF
 *
 * Return: buffer
 */

char *read_line()
{
	int buffsize = BUFFSIZE;
	int position = 0;
	char *buffer = (char *)malloc(sizeof(char) * buffsize);
	int c;

	/* NULL Buffer Check */
	if (!buffer)
	{
		perror("Buffer Allocation Error\n");
		exit(1);
	}

	/* Read Character Loop */
	while (1)
	{
		/* Read Character */
		c = getchar();

		/* Check for EOF */
		if (c == EOF || c == '\n')
		{
			buffer[position] = '\0';

			/* Do a check so that we don't return (null) when pressing Ctrl + D*/
			if (*buffer == '\0')
			{
				printf("Buffer has nothing\n");
				exit(1);
			}
			else
				return (buffer);
		}
		else
		{
			buffer[position] = c;
		}
		position++;
	}

	/* Memory Reallocation */
	if (position >= buffsize)
	{
		buffsize += BUFFSIZE;
		buffer = (char *)realloc(buffer, buffsize);

		/* NULL Buffer Check */
		if (!buffer)
		{
			perror("Memory Reacllocation Error\n");
			exit(1);
		}
	}

	return (buffer);
}

/**
 * tokenize- A function that parses the buffer
 * @buffer: Buffer contains string that is to be tokenized
 *
 * Return: Tokenized Buffer
 */
char **tokenize(char *buffer)
{
	int buffsize = BUFFSIZE, position = 0;
	char **tokens = (char **)malloc(sizeof(char *) * buffsize);
	/* tokens = list of strings (arguments) --> arguments == string (char *) */
	char *token;

	/* NULL Check for tokens */
	if (!tokens)
	{
		perror("Error Allocating Memory\n");
		exit(1);
	}

	token = strtok(buffer, TOK_DELIM);
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		/* Memory Reallcoation */
		if (position >= buffsize)
		{
			buffsize += BUFFSIZE;
			tokens = (char **)realloc(tokens, sizeof(char *) * buffsize);
			if (!tokens)
			{
				perror("Memory Reallocation Failed\n");
				exit(1);
			}
		}
	token = strtok(NULL, TOK_DELIM);
	}
	tokens[position] = NULL;
	return (tokens);
}

/**
 * proc_exe- Function that handles process execution
 * @args: Arguments to act on
 *
 * Return: (1) on Success
 */
int proc_exe(char **args)
{

	pid_t pid, wpid __attribute__((unused));
	int status;
	char **args_cpy = args;
	char *envp[] = 
	{
	"HOME=/",
	"PATH=/bin:/usr/bin:/usr/local/bin:/usr/local/sbin",
	"TZ=UTC0",
	"USER=BabyPanda",
	"LOGNAME=tarzan",
	0
	};


	pid = fork();
	if (pid == 0)
	{
		/* Print argument received from tokenize() */
		printf("Args[0] received: [%s]\n", args[0]);

		/* Print arguments that are being passed to argument vector */
		while (*args)
		{
			printf("Proceeding to execute with arg: [%s]\n", args[1]);
			args++;
		}

		/* Reset args ptr */
		args = args_cpy;

		/* Start Execution */
		if (execve(args[0], args, envp) == -1)
		{
			perror("Error Encountered while executing");
			exit(1);
		}
	}

	/* Handle Error (< 0)*/
	else if (pid < 0)
	{
		perror("Error Creating child process\n");
		exit(1);
	}

	/* Return to parent process */
	else
	{
		do {
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}
#endif /* FUNCS_H */
