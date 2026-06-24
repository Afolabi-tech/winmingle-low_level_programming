#include <stdlib.h>
#include "main.h"

/**
 * _strlen - returns length of a string
 * @s: string
 * Return: length
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len])
		len++;

	return (len);
}

/**
 * is_digit - checks if a string contains only digits
 * @s: string
 * Return: 1 if all digits, 0 otherwise
 */
int is_digit(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * errors - prints Error and exits
 */
void errors(void)
{
	int i;
	char error[] = "Error\n";

	for (i = 0; error[i]; i++)
		_putchar(error[i]);

	exit(98);
}

/**
 * main - multiplies two positive numbers
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	char *n1, *n2;
	int len1, len2, len, i, j, mul, carry, digit;
	int *result;

	if (argc != 3)
		errors();

	n1 = argv[1];
	n2 = argv[2];

	if (!is_digit(n1) || !is_digit(n2))
		errors();

	len1 = _strlen(n1);
	len2 = _strlen(n2);
	len = len1 + len2;

	result = malloc(sizeof(int) * len);
	if (result == NULL)
		return (1);

	for (i = 0; i < len; i++)
		result[i] = 0;

	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;

		for (j = len2 - 1; j >= 0; j--)
		{
			mul = (n1[i] - '0') * (n2[j] - '0');
			mul += result[i + j + 1] + carry;

			result[i + j + 1] = mul % 10;
			carry = mul / 10;
		}

		result[i] += carry;
	}

	i = 0;

	while (i < len - 1 && result[i] == 0)
		i++;

	for (; i < len; i++)
	{
		digit = result[i] + '0';
		_putchar(digit);
	}

	_putchar('\n');

	free(result);

	return (0);
}
