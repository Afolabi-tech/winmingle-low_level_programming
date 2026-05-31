#include <stdio.h>
#include "main.h"

/**
 * main - check the code
 *
 * Return: Always 0
 */
int main(void)
{
	printf("%d\n", _atoi("98"));
	printf("%d\n", _atoi("-402"));
	printf("%d\n", _atoi("----98"));
	printf("%d\n", _atoi("214748364"));
	printf("%d\n", _atoi("abc"));
	printf("%d\n", _atoi("402abc"));
	printf("%d\n", _atoi("98 and more"));
	printf("%d\n", _atoi("--402"));

	return (0);
}
