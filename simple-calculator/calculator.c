#include <stdio.h>
#include <stdlib.h>

/**
 * main - Welcomes the user presenting choices to it on how
 * it would like to use our awsome calculator for now only the
 * 0 option to quit works
 */
void main(void)
{
	int choice;

	printf("Welcome to the one and only Awsome Calculator!\n");
	printf("1) Add\n2) Subtract\n3) Multiply\n4) Divide\n0) Quit\n");
	printf("choice : ");
	scanf("%d", &choice);
	if (choice == 0)
	{
		printf("Bye !");
		return;
	}
}
