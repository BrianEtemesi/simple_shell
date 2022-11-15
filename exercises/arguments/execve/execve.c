#include <stdio.h>
#include <unistd.h>

int main (void)
{
	char *argv[] = {"/bin/ls", "-l", NULL};

	if (execve(argv[0], argv, NULL) == -1)
	{
		printf("Error\n");
	}
	
	return (0);
}
