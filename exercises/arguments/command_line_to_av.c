#include <stdio.h>
#include <string.h>

int main(void)
{

	char *my_token;
	char str1[] = "Baby Pandas Are Cool";
	my_token = strtok(str1, " ");

	while (my_token != NULL)
	{
		printf("%s\n", my_token);
		my_token = strtok(NULL, " ");
	}

	return (0);
}
