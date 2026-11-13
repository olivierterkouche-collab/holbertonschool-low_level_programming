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
	int vala;
	int valb;
	int result;

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
		if (choice == 1)
		{
			printf("1");
			printf("Enter the first value : ");
			scanf("%d", &vala);
			printf("Enter the second value : ");
			scanf("%d", &valb);
			result = vala + valb;
			printf("Result: %d", result);
		}
	}
	printf("Bye !");
	return (0);
}
