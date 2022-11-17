#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int ac, char **av)
{
	pid_t pid = getpid(); 
	pid_t ppid = getppid();

	/* Create a child process */
	pid = fork();

	/* Check if child process is created successfully */
	if (pid == -1)
	{
		perror("Unsuccessful\n");
		return (1);
	}
	
	if (pid == 0)
	{
		printf("[%u]: Child Process\n", pid);
	}

	else
	{
		sleep(10);
		printf("[%u]: Parent Process\n", ppid);
	}
	return (0);
}
