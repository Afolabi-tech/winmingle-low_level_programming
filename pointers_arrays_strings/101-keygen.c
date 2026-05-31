#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - generates a random valid password
 *
 * Return: Always 0
 */
int main(void)
{
	int sum = 2772;
	int value;

	srand(time(NULL));

	while (sum > 126)
	{
		value = (rand() % 94) + 33;
		putchar(value);
		sum -= value;
	}

	putchar(sum);
	putchar('\n');

	return (0);
}
