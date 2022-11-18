#include <stdio.h>

int main(void)
{
	int num;
	char ch; 
	printf("Enter Number: ");
	scanf("%d", &num);

	printf("Enter Character: ");
	fflush(stdin);
	scanf("%c", &ch);

	/* Print num */
	printf("Num entered is : [%d]\n", num);

	/* Print char */
	printf("Character entered is [%c]\n", ch);
	return (0);
}
