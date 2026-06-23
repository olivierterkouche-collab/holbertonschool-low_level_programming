#include <stdlib.h>
#include <time.h>
/**
 * main - Generates a random number stored in n and then prints it tells
 * if it is positive negative or equal to zero
 * Return: returns 0 when task is completed succesfully
 */
int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	for(n > 0)
	{
	printf("%d is positive\n", n);
	}
	for(n == 0)
	{
	printf("%d is zero\n", n);
	}
	for(n < 0)
	{
	printf("%d is negative\n", n);
	}
	return (0);
}
