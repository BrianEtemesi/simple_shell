#include <stdio.h>
#include <unistd.h>

int main(void)
{
	
	pid_t pid; 
	pid_t ppid;
	pid = fork(); /* Child Process was created */
	if (pid == -1)
	{
		perror("Unsuccessful\n");
		return (1);
	}

	if (pid == 0)
	{
		sleep(40);
		printf("Child Process Runnng\n");
	}
	else
	{
		ppid = getppid();
		printf("[%u]:Parent Process Running\n", ppid);
	}
	return (0);
}
