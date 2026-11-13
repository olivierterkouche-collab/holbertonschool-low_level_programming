#include <stdio.h>
#include <stdlib.h>

/**
 * main - Welcomes the user presenting choices to it on how
 * it would like to use our awsome calculator for now only the
 * 0 option to quit works
 *
 * Return: Returns 0 on program completion
 */
int main(void)
{
	int choice = 1;

	while (choice != 0)
	{
		printf("Welcome to the one and only Awsome Calculator!\n");
		printf("1) Add\n2) Subtract\n3) Multiply\n4) Divide\n0) Quit\n");
		printf("choice : ");
		scanf("%d", &choice);
		if (choice < 0 || choice > 4)
		{
			printf("%d\nInvalid choice\n", choice);
		}
	}
	printf("Bye !");
	return (0);
}
