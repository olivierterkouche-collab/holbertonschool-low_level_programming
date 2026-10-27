#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Gives a random value to n then
 * prints it's last digit precising if
 * it is lower than 6 greater than 5
 * or equal to 0 if n is negative it uses
 * it's absolute value
 *
 * Return: Returns 0 if the program was executed correctly
 */

int main(void)
{
int n;
int absVal;
int lastDigt;

srand(time(0));
n = rand() - RAND_MAX / 2;
if (n < 0)
{
	absVal = n * -1;
	lastDigt = (absVal % 10) * -1;
	if (lastDigt < 6 && lastDigt != 0)
	{
		printf("Last digit of %d is %d and is less than 6 and not 0\n", n, lastDigt);
	}
	else
	{
		printf("Last digit of %d is %d and is 0\n", n, lastDigt);
	}
}
else
{
	lastDigt = n % 10;
	if (lastDigt > 5)
	{
		printf("Last digit of %d is %d and is greater than 5\n", n, lastDigt);
	}
	else if (lastDigt < 6 && lastDigt != 0)
	{
		printf("Last digit of %d is %d and is less than 6 and not 0\n", n, lastDigt);
	}
	else
	{
		printf("Last digit of %d is %d and is 0\n", n, lastDigt);
	}
}
return (0);
}
