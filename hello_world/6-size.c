#include <stdio.h>

/**
 * main - Each printf command prints a text includind the size of the type
 * it talks about
 * Retrun: Returns 0 if everythings works as planned
 */
int main(void)
{
	printf("Size of a char: %zu byte(s)\n"sizeof(char));
	printf("Size of an int: %zu byte(s)\n"sizeof(int));
	printf("Size of a long int: %zu byte(s)\n"sizeof(long int));
	printf("Size of a long long int: %zu byte(s)\n"sizeof(long long int));
	printf("Size of a float: %zu bytes(s)\n"sizeof(float));
	return (0);
}
