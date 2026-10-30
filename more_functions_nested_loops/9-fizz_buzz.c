#include <stdio.h>

/**
 * fizz_buzz - prints all numbers from 1 to 100 rplacing
 * replacing multiples of 3 and 5 by Fizz, Buzz or Fizz Buzz
 */
void fizz_buzz(void)
{
	int i;

	for (i = 1; i <= 100; i++)
	{
		if ((i % 3) == 0 && (i % 5) == 0)
		{
			printf("Fizz Buzz ");
		}
		else if ((i % 3) == 0 || (i % 5) == 0)
		{
			if ((i % 3) == 0)
			{
				printf("Fizz ");
			}
			else
			{
				printf("Buzz ");
			}
		}
		else
		{
			printf("%d ", i);
		}
	}
}
