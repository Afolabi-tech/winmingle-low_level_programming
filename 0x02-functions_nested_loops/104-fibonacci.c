#include <stdio.h>

/**
 * main - prints the first 98 Fibonacci numbers
 *
 * Return: Always 0
 */
int main(void)
{
	unsigned long a = 1, b = 2, sum;
	unsigned long a1, a2, b1, b2, sum1, sum2;
	int count;

	printf("%lu, %lu", a, b);

	/* Print first 90 Fibonacci numbers normally */
	for (count = 3; count <= 90; count++)
	{
		sum = a + b;
		printf(", %lu", sum);

		a = b;
		b = sum;
	}

	/* Split large numbers into two parts */
	a1 = a / 1000000000;
	a2 = a % 1000000000;
	b1 = b / 1000000000;
	b2 = b % 1000000000;

	/* Print remaining Fibonacci numbers */
	for (count = 91; count <= 98; count++)
	{
		sum1 = a1 + b1;
		sum2 = a2 + b2;

		if (sum2 >= 1000000000)
		{
			sum1 += 1;
			sum2 %= 1000000000;
		}

		printf(", %lu%09lu", sum1, sum2);

		a1 = b1;
		a2 = b2;
		b1 = sum1;
		b2 = sum2;
	}

	printf("\n");

	return (0);
}
