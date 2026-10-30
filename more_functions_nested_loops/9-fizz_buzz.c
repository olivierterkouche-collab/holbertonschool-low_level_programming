#include <stdio.h>

void fizz_buzz(void);

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
			printf("FizzBuzz ");
		}
		else if ((i % 3) == 0 || (i % 5) == 0)
		{
			if ((i % 3) == 0)
			{
				printf("Fizz ");
			}
			else
			{
				printf("Buzz");
				if (i != 100)
				{
					printf(" ");
				}
				else
				{
					printf("\n")
				}
			}
		}
		else
		{
			printf("%d ", i);
		}
	}
}

/**
 * main - executes fonction fizz_buzz
 *
 * Return: Allways 0
 */
int main(void)
{
	fizz_buzz();
	return (0);
}
