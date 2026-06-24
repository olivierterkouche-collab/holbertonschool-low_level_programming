#include <stdlib.h>
#include <time.h>
#include <stdio.h>
/**
 * main - Generates a random number extract the last digit of it
 * then prints both n and the last digit before say more or less
 * than 5 or equal to 0
 * Return: returns value 0 if the program was executed sucessfully
 */
int main(void)
{
	int n;
	int lastDigit;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	lastDigit = n % 10
	if (lastDigit > 5)
	{
	printf("Last digit of %d is %d and is greater than 5\n", n, lastDigit);
	}
	else if (lastDigit < 6 && != O)
	{
	printf("Last digit of %d is %d and is less than 6 and not 0\n", n, lastDigit);
	}
	else
	{
	printf("Last digit of %d is %d and is 0\n", n, lastDigit);
	}
	return (0);
}
