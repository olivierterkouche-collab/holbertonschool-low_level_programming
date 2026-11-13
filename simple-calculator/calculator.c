#include <stdio.h>
#include <stdlib.h>

void addition(void);
void subtraction(void);

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
		if (choice == 1)
		{
			addition();
		}
		if (choice == 2)
		{
			subtraction();
		}
	}
	printf("Bye !");
	return (0);
}

/**
 * addition - Prompts the user for 2 numbers then adds them together
 * and prints the result
 */
void addition(void)
{
	int a;
	int b;
	int result;

	printf("Enter the first value : ");
	scanf("%d", &a);
	printf("Enter the second value : ");
	scanf("%d", &b);
	result = a + b;
	printf("Result: %d\n", result);
}

/**
 * subtraction - Prompts the user for 2 numbers
 * then subtract the second to the first
 * and prints the result
 */
void subtraction(void)
{
	int a;
	int b;
	int result;

	printf("Enter the first value : ");
	scanf("%d", &a);
	printf("Enter the second value : ");
	scanf("%d", &b);
	result = a - b;
	printf("Result: %d\n", result);
}
