#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
	pid_t my_pid; 
	pid_t my_ppid;

	my_pid = getpid();
	my_ppid = getppid();

	printf("PID: %u\n", my_pid);
	printf("PPID: %u\n", my_ppid);
	return (0);
}
