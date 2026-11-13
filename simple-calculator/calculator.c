#include <stdio.h>
#include <stdlib.h>

void addition(void);
void subtraction(void);
void multiplication(void);
void division(void);

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
		if (choice == 3)
		{
			multiplication();
		}
		if (choice == 4)
		{
			division();
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

/**
 * multiplication - Prompts the user for 2 numbers and multiply them
 * then prints the result
 */
void multiplication(void)
{
	int a;
	int b;
	int result;

	printf("Enter the first value : ");
	scanf("%d", &a);
	printf("Enter the second value : ");
	scanf("%d", &b);
	result = a * b;
	printf("Result: %d\n", result);
}

/**
 * subtraction - Prompts the user for 2 numbers
 * then divides the first by the second
 * and prints the result
 * disposes of a security fobiding division by zero
 */
void division(void)
{
	int a;
	int b;
	int result;

	printf("Enter the first value : ");
	scanf("%d", &a);
	printf("Enter the second value : ");
	scanf("%d", &b);
	if (b == 0)
	{
		printf("Error: division by zero\n");
		return;
	}
	result = a / b;
	printf("Result: %d\n", result);
}
